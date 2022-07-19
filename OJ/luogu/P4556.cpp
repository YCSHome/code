#include <vector>
#include <cstdio>

using namespace std;

const int kMaxN = 1e5 + 1;

vector<int> go[kMaxN];
int maxk = 0;
struct node { // 动态开点版
  int l, r;
  int maxValue, maxPos;
  node *_left, *_right;

  friend node * left(node * p);
  friend node * right(node * p);

  void pushup() {
    maxValue = max(left(this)->maxValue, right(this)->maxValue);
    maxPos = left(this)->maxPos;
    if (left(this)->maxValue < right(this)->maxValue) { maxPos = right(this)->maxPos; }
  }
}b[100 * kMaxN];
int tot = 0;

node * newnode(int l, int r) {
  b[tot].l = l;
  b[tot].r = r;
  b[tot].maxPos = l;
  return &b[tot++];
}

node * left(node* p) {
  return p->_left == nullptr ? p->_left = newnode(p->l, (p->r + p->l) >> 1) : p->_left;
}

node * right(node* p) {
  return p->_right == nullptr ? p->_right = newnode(((p->r + p->l) >> 1) + 1, p->r) : p->_right;
}
node * merge(node * p1, node * p2) {
  if (p1 == nullptr) { return p2; }
  if (p2 == nullptr) { return p1; }
  if (p1->l == p1->r) {
    p1->maxValue += p2->maxValue;
    p1->maxPos = p1->l;
    return p1;
  }
  p1->_left = merge(p2->_left, p1->_left);
  p1->_right = merge(p1->_right, p2->_right);
  p1->pushup();
  return p1;
}

// 动态开点线段树
class SegmentTree {
private:
  node * root;

  void add(node * p, int x, int k) {
    if (p->l > x || p->r < x) { return; }
    if (x <= p->l && p->r <= x) {
      p->maxValue += k;
      return;
    }
    add(left(p), x, k);
    add(right(p), x, k);
    p->pushup();
  }

public:

  inline void add(int x, int k) {
    if (root == nullptr) root = newnode(1, maxk);
    add(root, x, k);
  }
  inline int getMax() {
    if (root == nullptr) return 0;
    return root->maxValue == 0 ? 0 : root->maxPos;
  }
  friend void dfs(int, int);
}tree[kMaxN];
// 吓得够呛

int depth[kMaxN];
int father[kMaxN][21];

void init(int x, int f) {
  depth[x] = depth[f] + 1;
  father[x][0] = f;
  for (int i = 1; i <= 20; i++) {
    father[x][i] = father[father[x][i - 1]][i - 1];
  }
  for (int i : go[x]) {
    if (i == f) continue;
    init(i, x);
  }
}

inline int get(int x, int y) {
  if (depth[x] < depth[y]) swap(x, y);
  for (short i = 20; i >= 0; i--) {
    if (depth[father[x][i]] >= depth[y]) {
      x = father[x][i];
    }
  }
  if (x == y) return x;
  for (short i = 20; i >= 0; i--) {
    if (father[x][i] != father[y][i]) {
      x = father[x][i];
      y = father[y][i];
    }
  }
  return father[x][0];
}

int n, m;
int ans[kMaxN];
int x[kMaxN], y[kMaxN], k[kMaxN];

void dfs(int x, int f) {
  for (int i : go[x]) {
    if (i == f) continue;
    dfs(i, x);
    tree[x].root = merge(tree[x].root, tree[i].root);
  }
  ans[x] = tree[x].getMax();
}

signed main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    go[x].push_back(y);
    go[y].push_back(x);
  }
  init(1, 0);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &x[i], &y[i], &k[i]);
    maxk = max(maxk, k[i]);
  }
  for (int i = 1; i <= m; i++) {
    int p = get(x[i], y[i]);
    if (father[p][0] != 0) {
      tree[father[p][0]].add(k[i], -1);
    }
    tree[p].add(k[i], -1);
    tree[x[i]].add(k[i], 1);
    tree[y[i]].add(k[i], 1);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}

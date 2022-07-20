#include <cstring>
#include <cerrno>
#include <vector>
#include <ios>

using namespace std;

const int kMaxN = 1e6;

struct line {
  int leftColor, rightColor;
  int count;
};

line merge(line l, line r) {
  line temp;
  temp.leftColor = l.leftColor;
  temp.rightColor = r.rightColor;
  temp.count = l.count + r.count + (l.rightColor == r.leftColor);
  return temp;
}

class SegmentTree {
private:
  struct node {
    line value;
    int l, r;
    int lazy = 0;
    node *left, *right;

    void pushup() {
      value = merge(left->value, right->value);
    }

    void setColor(int x) {
      value.leftColor = value.rightColor = x;
      value.count = r - l;
      lazy = x;
    }

    void pushdown() {
      if (lazy != 0) {
        left->setColor(lazy);
        right->setColor(lazy);
        lazy = 0;
      }
    }
  } * root;

  void build(node* p, int l, int r) {
    p->l = l, p->r = r;
    if (l == r) {
      return;
    }
    int mid = (l + r) >> 1;
    build(p->left = new node, l, mid);
    build(p->right = new node, mid + 1, r);
    p->pushup();
  }

  void setColor(node * p, int l, int r, int k) {
    if (p->l > r || p->r < l) {
      return;
    }
    if (l <= p->l && p->r <= r) {
      p->setColor(k);
      return;
    }
    p->pushdown();
    setColor(p->left, l, r, k);
    setColor(p->right, l, r, k);
    p->pushup();
  }

  line get(node* p, int l, int r) {
    if (l <= p->l && p->r <= r) {
      return p->value;
    }
    p->pushdown();
    int mid = (p->l + p->r) >> 1;
    line a, b;
    bool A = false, B = false;
    if (l <= mid) { A = true; a = get(p->left, l, r); }
    if (mid < r) { B = true; b = get(p->right, l, r); }
    if (A && !B) return a;
    if (!A && B) return b;
    return merge(a, b);
  }

public:
  void build(int n) { build(root = new node, 1, n); }
  line get(int l, int r) { return get(root, l, r); }
  void setColor(int l, int r, int k) { setColor(root, l, r, k); }
}t;


// 树链剖分部分
vector<int> go[kMaxN];
int father[kMaxN];
int size[kMaxN];
int depth[kMaxN];
int heavySon[kMaxN];
int top[kMaxN];
int p[kMaxN];
int tot = 0;
int tot2 = 0;
bool vis[kMaxN];

void dfs1(int u, int f) {
  if (vis[u]) return;
  vis[u] = true;
  ::size[u] = 1;
  depth[u] = depth[f] + 1;
  father[u] = f;
  for (int i : go[u]) {
    if (i == f) { continue; }
    dfs1(i, u);
    ::size[u] += ::size[i];
    if (::size[i] > ::size[heavySon[u]]) {
      heavySon[u] = i;
    }
  }
}

void dfs2(int u, int f, int top) {
  if (vis[u]) return;
  vis[u] = true;
  ::top[u] = top;
  p[u] = ++tot;
  if (heavySon[u]) {
    dfs2(heavySon[u], u, top);
  }
  for (int i : go[u]) {
    if (i == f || i == heavySon[i]) { continue; }
    dfs2(i, u, i);
  }
}

void add(int x, int y, int k) {
  while (top[x] != top[y]) {
    t.setColor(p[top[x]], p[x], k);
    x = father[top[x]];
  }
  t.setColor(p[y], p[x], k);
}

int _ask(int x, int y) {
  bool flag = false;
  line a, b, temp;
  a = {0, 0, 0};
  b = {0, 0, 0};
  while (top[x] != top[y]) {
    if (depth[top[x]] < depth[top[y]]) {
      flag = !flag;
      swap(x, y);
    }
    temp = t.get(p[top[x]], p[x]);
    if (flag) {
      b = {
        temp.leftColor, b.rightColor, b.count + temp.count + (b.leftColor == temp.rightColor)
      };
    } else {
      a = {
        a.leftColor, temp.leftColor, (a.rightColor == temp.rightColor) + a.count + temp.count
      };
    }
    x = father[top[x]];
  }
  if (depth[x] < depth[y]) {
    flag = !flag;
    swap(x, y);
  }
  temp = t.get(p[y], p[x]);
  if (flag) {
    b = {
      temp.leftColor, b.rightColor, b.count + temp.count + (b.leftColor == temp.rightColor)
    };
  } else {
    a = {
      a.leftColor, temp.leftColor, (a.rightColor == temp.rightColor) + a.count + temp.count
    };
  }
  return merge(a, b).count;
}

void update(int x, int y, int k) {
  while (top[x] != top[y]) {
    if (depth[top[x]] < depth[top[y]]) { swap(x, y); }
    t.setColor(p[top[x]], p[x], k);
    x = father[top[x]];
  }
  if (depth[x] < depth[y]) swap(x, y);
  t.setColor(p[y], p[x], k);
}

line ask(int x, int y) {
  line a = {0, 0, 0};
  while (top[x] != top[y]) {
    if (a.leftColor == 0) {
      a = ::t.get(p[top[x]], p[x]);
    } else {
      a = merge(::t.get(p[top[x]], p[x]), a);
    }
    x = father[top[x]];
  }
  a = merge(t.get(p[y], p[x]), a);
  return a;
}

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  tot = tot2 = 0;
  memset(father, 0, sizeof(father));
  memset(depth, 0, sizeof(depth));
  memset(top, 0, sizeof(top));
  memset(heavySon, 0, sizeof(heavySon));
  t.build(n);
  for (int i = 1; i <= n; i++) { go[i].clear(); }
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    go[x].push_back(y), go[y].push_back(x);
  }
  memset(vis, false, sizeof(vis));
  dfs1(1, 0);
  memset(vis, false, sizeof(vis));
  dfs2(1, 0, 1);
  for (int i = 1; i <= n; i++) { t.setColor(i, i, -i); }
  for (int i = 1; i <= m; i++) {
    int opt;
    int x, y;
    scanf("%d%d%d", &opt, &x, &y);
    if (opt == 1) {
      update(x, y, i);
    } else {
      printf("%d\n", _ask(x, y));
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) { solve(); }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int n, q;
int root = 1;
int a[MAXN];

// 建边
struct edge {
  int u, v, next;
} e[MAXN];

int tot = 0;
int head[MAXN];

void add(int u, int v) {
  e[++tot] = {u, v, head[u]};
  head[u] = tot;
}

// 线段树
class SegmentTree {
 private:
  struct node {
    node *left, *right;
    long long l, r;
    long long value;
    long long lazy;
    node() {
      left = right = nullptr;
      l = r = value = lazy = 0;
    }
  } * root;

  void pushdown(node* p) {
    if (p->left == nullptr) return;
    if (p->lazy) {
      p->left->value += (p->left->r - p->left->l + 1) * p->lazy;
      p->right->value += (p->right->r - p->right->l + 1) * p->lazy;
      p->left->lazy += p->lazy;
      p->right->lazy += p->lazy;
    }
    p->lazy = 0;
  }

  void pushup(node* p) { p->value = p->left->value + p->right->value; }

  void build(node* p, int l, int r) {
    p->l = l;
    p->r = r;
    if (l == r) {
      return;
    }
    int mid = (l + r) >> 1;
    build(p->left = new node, l, mid);
    build(p->right = new node, mid + 1, r);
    pushup(p);
  }

  void add(node* p, int l, int r, long long d) {
    if (l > p->r || p->l > r) return;
    if (l <= p->l && p->r <= r) {
      p->value += (p->r - p->l + 1) * d;
      p->lazy += d;
      return;
    }
    pushdown(p);
    add(p->left, l, r, d);
    add(p->right, l, r, d);
    pushup(p);
  }

  long long get(node* p, int l, int r) {
    if (l > p->r || p->l > r) return 0;
    if (l <= p->l && p->r <= r) {
      return p->value;
    }
    pushdown(p);
    return get(p->left, l, r) + get(p->right, l, r);
  }

 public:
  void build(int n) { build(root = new node, 1, n); }

  void add(int l, int r, int d) { add(root, l, r, d); }

  long long get(int l, int r) { return get(root, l, r); }
};

// LCA
int father[MAXN][30];
int depth[MAXN];
int size[MAXN];
int pos[MAXN];
int tot2 = 0;

void init(int u, int fa) {
  father[u][0] = fa;
  depth[u] = depth[fa] + 1;
  size[u] = 1;
  pos[u] = ++tot2;
  for (int i = 1; i < 30; i++) {
    father[u][i] = father[father[u][i - 1]][i - 1];
  }
  for (int i = head[u]; i; i = e[i].next) {
    if (e[i].v == fa) continue;
    init(e[i].v, u);
    size[u] += size[e[i].v];
  }
}

int find(int x, int y) {
  if (depth[x] < depth[y]) swap(x, y);
  for (int i = 29; i >= 0; i--) {
    if (depth[father[x][i]] >= depth[y]) {
      x = father[x][i];
    }
  }
  if (x == y) return x;
  for (int i = 29; i >= 0; i--) {
    if (father[x][i] != father[y][i]) {
      x = father[x][i];
      y = father[y][i];
    }
  }
  return father[x][0];
}

// 查询在root为根的情况下，x和y的最近公共祖先
int LCA(int root, int x, int y) {
  int f1 = find(x, y);
  int f2 = find(root, y);
  int f3 = find(x, root);
  int ans = f1;
  if (depth[ans] < depth[f2]) ans = f2;
  if (depth[ans] < depth[f3]) ans = f3;
  return ans;
}

SegmentTree Tree;

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    cin >> x >> y;
    add(y, x);
    add(x, y);
  }
  Tree.build(n);
  init(1, 0);
  for (int i = 1; i <= n; i++) {
    Tree.add(pos[i], pos[i], a[i]);
  }
  for (int i = 1; i <= q; i++) {
    int opt, u;
    cin >> opt;
    if (opt == 1) {
      cin >> root;
    } else if (opt == 2) {
      int x = u, y, w;
      cin >> x >> y >> w;
      u = LCA(root, x, y);

      if (u == root) {
        Tree.add(1, n, w);
      } else {
        int p = find(u, root);
        if (u != p) {
          Tree.add(pos[u], pos[u] + size[u] - 1, w);
        } else {
          p = root;
          for (int i = 29; i >= 0; i--) {
            if (depth[father[p][i]] > depth[u]) p = father[p][i];
          }
          Tree.add(1, n, w);
          Tree.add(pos[p], pos[p] + size[p] - 1, -w);
        }
      }
    } else {
      cin >> u;
      if (u == root) {
        cout << Tree.get(1, n) << endl;
      } else {
        int p = find(u, root);
        if (u != p) {
          cout << Tree.get(pos[u], pos[u] + size[u] - 1) << endl;
        } else {
          p = root;
          for (int i = 29; i >= 0; i--) {
            if (depth[father[p][i]] > depth[u]) p = father[p][i];
          }
          cout << Tree.get(1, n) - Tree.get(pos[p], pos[p] + size[p] - 1)
               << endl;
        }
      }
    }
  }
  return 0;
}

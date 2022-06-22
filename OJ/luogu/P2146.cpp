#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e6;

class SegmentTree {
private:
  struct node {
    int l, r;
    int value;
    bool clear_lazy;
    bool fill_lazy;
    node * left, * right;

    node(int l, int r) : l(l), r(r) {
      clear_lazy = fill_lazy = false;
    }

    void clear() {
      clear_lazy = true;
      fill_lazy = false;
      value = 0;
    }

    void fill() {
      fill_lazy = true;
      clear_lazy = false;
      value = (r - l + 1);
    }
  }*root;

  void pushup(node * p) {
    p->value = p->left->value + p->right->value;
  }

  void pushdown(node * p) {
    if (p->left == nullptr) return;
    if (p->clear_lazy) {
      p->left->clear();
      p->right->clear();
      p->clear_lazy = false;
    }
    if (p->fill_lazy) {
      p->left->fill();
      p->right->fill();
      p->fill_lazy = false;
    }
  }

  void build(node * p, int l, int r) {
    if (l == r) {
      return;
    }
    int mid = (r + l) >> 1;
    build(p->left = new node(l, mid), l, mid);
    build(p->right = new node(mid + 1, r), mid + 1, r);
    pushup(p);
  }

  void clear(node * p, int l, int r) {
    if (l > p->r || p->l > r) {
      return;
    }
    if (l <= p->l && p->r <= r) {
      p->clear();
      return;
    }
    pushdown(p);
    clear(p->left, l, r);
    clear(p->right, l, r);
    pushup(p);
  }

  void fill(node * p, int l, int r) {
    if (l > p->r || p->l > r) {
      return;
    }
    if (l <= p->l && p->r <= r) {
      p->fill();
      return;
    }
    pushdown(p);
    fill(p->left, l, r);
    fill(p->right, l, r);
    pushup(p);
  }

  int get(node * p, int l, int r) {
    if (l > p->r || p->l > r) {
      return 0;
    }
    if (l <= p->l && p->r <= r) {
      return p->value;
    }
    pushdown(p);
    return get(p->left, l, r) + get(p->right, l, r);
  }

public:
  void build(int n) {
    build(root = new node(1, n), 1, n);
  }

  int get(int l, int r) {
    return get(root, l, r);
  }

  void clear(int l, int r) { clear(root, l, r); }
  void fill(int l, int r) { fill(root, l, r); }
}t;

// 建边
struct edge {
  int v, next;
}e[kMaxN];

int EdgeTotal = 0;
int head[kMaxN];

void add_edge(int u, int v) {
  e[++EdgeTotal] = {v, head[u]};
  head[u] = EdgeTotal;
}

// 初始化
int Size[kMaxN];
int pos[kMaxN];
int depth[kMaxN];
int father[kMaxN];
int heavy_son[kMaxN];
int top[kMaxN];
int total = 0;

void dfs1(int u, int f) {
  depth[u] = depth[f] + 1;
  father[u] = f;
  Size[u] = 1;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].v;
    if (v == f) continue;
    dfs1(v, u);
    Size[u] += Size[v];
    if (Size[v] > Size[heavy_son[u]]) {
      heavy_son[u] = v;
    }
  }
}

void dfs2(int u, int top_) {
  pos[u] = ++total;
  top[u] = top_;
  if (heavy_son[u]) {
    dfs2(heavy_son[u], top_);
  }
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].v;
    if (v == father[v] || v == heavy_son[u]) continue;
    dfs2(v, v);
  }
}

void install(int x) {
  int y = 1;
  while (top[x] != top[y]) {
    if (depth[top[x]] < depth[top[y]]) {
      swap(x, y);
    }
    t.fill(pos[top[x]], pos[x]);
    x = father[top[x]];
  }
  if (depth[x] > depth[y]) swap(x, y);
  t.fill(pos[x], pos[y]);
}

void uninstall(int x) {
  t.clear(pos[x], pos[x] + Size[x] - 1);
}

int n, m;

int main() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    add_edge(x + 1, i);
  }
  dfs1(1, 0);
  dfs2(1, 1);
  t.build(n);
  cin >> m;
  string str;
  while (m--) {
    int k = t.get(1, n), x;
    cin >> str >> x;
    x++;
    if (str == "install") {
      install(x);
    } else {
      uninstall(x);
    }
    cout << abs(t.get(1, n) - k) << endl;
  }
  return 0;
}

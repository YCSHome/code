#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e6;

class SegmentTree {
private:
  struct node {
    int value, l, r;
    int lazy_tag;
    int Max;
    node * left, * right;
    node(int l, int r) : l(l), r(r) {
      left = right = nullptr;
      lazy_tag = 0;
    }

    void add(int v) {
      lazy_tag += v;
      value += (r - l + 1) * v;
      Max += v;
    }
  } * root;

  void pushdown(node * p) {
    if (p->left != nullptr) {
      p->left->add(p->lazy_tag);
      p->right->add(p->lazy_tag);
      p->lazy_tag = 0;
    }
  }

  void pushup(node * p) {
    p->value = p->left->value + p->right->value;
    p->Max = max(p->left->Max, p->right->Max);
  }

  int get(node * p, int l, int r) {
    if (p->r < l || p->l > r) {
      return 0;
    }
    if (p->l >= l && p->r <= r) {
      return p->value;
    }
    pushdown(p);
    return get(p->left, l, r) + get(p->right, l, r);
  }

  void build(node * p, int * array, int l, int r) {
    if (l == r) {
      p->value = array[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p->left = new node(l, mid), array, l, mid);
    build(p->right = new node(mid + 1, r), array, mid + 1, r);
    pushup(p);
  }

  void add(node * p, int l, int r, int k) {
    if (p->r < l || p->l > r) { return; }
    if (p->l >= l && p->r <= r) {
      p->add(k);
      return;
    }
    pushdown(p);
    add(p->left, l, r, k);
    add(p->right, l, r, k);
    pushup(p);
  }

  int get_max(node * p, int l, int r) {
    if (p->r < l || p->l > r) {
      return -INT_MAX;
    }
    if (p->l >= l && p->r <= r) {
      return p->Max;
    }
    pushdown(p);
    return max(get_max(p->left, l, r), get_max(p->right, l, r));
  }
public:
  void build(int * array, int n) { build(root = new node(1, n), array, 1, n); }
  void add(int l, int r, int k)  { add(root, l, r, k); }
  int  get(int l, int r)         { return get(root, l, r); }
  int  get_max(int l, int r)     { return get_max(root, l, r); };
}t;

struct edge {
  int v, next;
}e[kMaxN];

int EdgeTotal = 0;
int head[kMaxN];

void add_edge(int u, int v) {
  e[++EdgeTotal] = {v, head[u]};
  head[u] = EdgeTotal;
}

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
    if (v == father[u] || v == heavy_son[u]) continue;
    dfs2(v, v);
  }
}

int get_max(int x, int y) {
  int res = INT_MIN;
  while (top[x] != top[y]) {
    if (depth[top[x]] < depth[top[y]]) {
      swap(x, y);
    }
    res = max(res, t.get_max(pos[top[x]], pos[x]));
    x = father[top[x]];
  }
  if (depth[x] > depth[y]) {
    swap(x, y);
  }
  res = max(res, t.get_max(pos[x], pos[y]));
  return res;
}

int get(int x, int y) {
  int res = 0;
  while (top[x] != top[y]) {
    if (depth[top[x]] < depth[top[y]]) {
      swap(x, y);
    }
    res += t.get(pos[top[x]], pos[x]);
    x = father[top[x]];
  }
  if (depth[x] > depth[y]) {
    swap(x, y);
  }
  res += t.get(pos[x], pos[y]);
  return res;
}

int n, m;
int a[kMaxN];

int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    add_edge(x, y);
    add_edge(y, x);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  t.build(Size, n);
  dfs1(1, 0);
  dfs2(1, 1);
  for (int i = 1; i <= n; i++) {
    t.add(pos[i], pos[i], a[i]);
  }
  cin >> m;
  while (m--) {
    string str;
    int a, b;
    cin >> str >> a >> b;
    if (str == "CHANGE") {
      t.add(pos[a], pos[a], -t.get(pos[a], pos[a]));
      t.add(pos[a], pos[a], b);
    } else if (str == "QMAX") {
      cout << get_max(a, b) << endl;
    } else {
      cout << get(a, b) << endl;
    }
  }
  return 0;
}

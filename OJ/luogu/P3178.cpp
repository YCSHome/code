#include <bits/stdc++.h>

using namespace std;

const long long kMaxN = 1e6;

class SegmentTree {
private:
  struct node {
    long long value, l, r;
    long long lazy_tag;
    node * left, * right;
    node(long long l, long long r) : l(l), r(r) {
      left = right = nullptr;
      lazy_tag = 0;
    }

    void add(long long v) {
      lazy_tag += v;
      value += (r - l + 1) * v;
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
  }

  long long get(node * p, long long l, long long r) {
    if (p->r < l || p->l > r) {
      return 0;
    }
    if (p->l >= l && p->r <= r) {
      return p->value;
    }
    pushdown(p);
    return get(p->left, l, r) + get(p->right, l, r);
  }

  void build(node * p, long long * array, long long l, long long r) {
    if (l == r) {
      p->value = array[l];
      return;
    }
    long long mid = (l + r) >> 1;
    build(p->left = new node(l, mid), array, l, mid);
    build(p->right = new node(mid + 1, r), array, mid + 1, r);
    pushup(p);
  }

  void add(node * p, long long l, long long r, long long k) {
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
public:
  void build(long long * array, long long n) { build(root = new node(1, n), array, 1, n); }
  void add(long long l, long long r, long long k)  { add(root, l, r, k); }
  long long  get(long long l, long long r)         { return get(root, l, r); }
}t;

struct edge {
  long long v, next;
}e[kMaxN];

long long EdgeTotal = 0;
long long head[kMaxN];

void add_edge(long long u, long long v) {
  e[++EdgeTotal] = {v, head[u]};
  head[u] = EdgeTotal;
}

long long Size[kMaxN];
long long pos[kMaxN];
long long depth[kMaxN];
long long father[kMaxN];
long long heavy_son[kMaxN];
long long top[kMaxN];
long long total = 0;
long long a[kMaxN];

void dfs1(long long u, long long f) {
  depth[u] = depth[f] + 1;
  father[u] = f;
  Size[u] = 1;
  for (long long i = head[u]; i; i = e[i].next) {
    long long v = e[i].v;
    if (v == f) continue;
    dfs1(v, u);
    Size[u] += Size[v];
    if (Size[v] > Size[heavy_son[u]]) {
      heavy_son[u] = v;
    }
  }
}

void dfs2(long long u, long long top_) {
  pos[u] = ++total;
  top[u] = top_;
  if (heavy_son[u]) {
    dfs2(heavy_son[u], top_);
  }
  for (long long i = head[u]; i; i = e[i].next) {
    long long v = e[i].v;
    if (v == father[u] || v == heavy_son[u]) continue;
    dfs2(v, v);
  }
}

long long get(long long x, long long y) {
  long long res = 0;
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

long long n, m;

int main() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long i = 1; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    add_edge(x, y);
    add_edge(y, x);
  }
  t.build(Size, n);
  dfs1(1, 0);
  dfs2(1, 1);
  for (long long i = 1; i <= n; i++) {
    t.add(pos[i], pos[i], a[i]);
  }
  while (m--) {
    long long opt, x;
    scanf("%lld%lld", &opt, &x);
    if (opt == 1) {
      long long a;
      scanf("%lld", &a);
      t.add(pos[x], pos[x], a);
    } else if (opt == 2) {
      long long a;
      scanf("%lld", &a);
      t.add(pos[x], pos[x] + Size[x] - 1, a);
    } else {
      printf("%lld\n", get(1, x));
    }
  }
  return 0;
}

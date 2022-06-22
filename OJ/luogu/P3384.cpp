#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e6;

int n;
int m;
long long p;
int root;
int a[kMaxN];

class SegmentTree {
private:
  struct node {
    long long value, l, r;
    long long lazy_tag;
    node * left, * right;
    node(int l, int r) : l(l), r(r) {
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

  long long get(node * p, int l, int r) {
    if (p->r < l || p->l > r) {
      return 0;
    }
    if (p->l >= l && p->r <= r) {
      return p->value;
    }
    pushdown(p);
    return get(p->left, l, r) + get(p->right, l, r);
  }

  void build(node * p, int l, int r) {
    if (l == r) {
      return;
    }
    int mid = (l + r) >> 1;
    build(p->left = new node(l, mid), l, mid);
    build(p->right = new node(mid + 1, r), mid + 1, r);
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
public:
  void build(int n)              { build(root = new node(1, n), 1, n); }
  void add(int l, int r, int k)  { add(root, l, r, k); }
  long long  get(int l, int r)         { return get(root, l, r); }
};

class Group {
private:
  struct edge {
    int v, w;
    edge * next;
  };
  vector<edge*> head_;
public:
  void init(int n) { head_.resize(n + 1); }

  void add(int u, int v, int w) {
    head_[u] = new edge {v, w, head_[u]};
  }

  edge * get(int head) {
    return head_[head];
  }
}g;

class Tree {
private:
  struct TreeNode {
    int p;
    int size;
    int depth;
    TreeNode * heavy_son;
    TreeNode * top;
    TreeNode * father;
  }nodes[kMaxN];

  SegmentTree t_;
  int Total = 0;

  void init1(TreeNode * p, TreeNode * father) {
    p->size = 1;
    p->depth++;
    p->father = father;
    for (auto i = g.get(p - nodes); i; i = i->next) {
      auto v = nodes + i->v;
      if (v == father) continue;
      v->depth = p->depth;
      init1(v, p);
      p->size += v->size;
      if (p->heavy_son == nullptr || p->heavy_son->size < v->size) {
        p->heavy_son = v;
      }
    }
  }

  void init2(TreeNode * p, TreeNode * top) {
    p->p = ++Total;
    p->top = top;
    if (p->heavy_son) {
      init2(p->heavy_son, top);
    }

    for (auto i = g.get(p - nodes); i; i = i->next) {
      auto v = nodes + i->v;
      if (v == p->father || v == p->heavy_son) continue;
      init2(v, v);
    }
  }

  int find(TreeNode * x, TreeNode * y) {
    while (x->top != y->top) {
      if (x->top->depth < y->top->depth) {
        swap(x, y);
      }
      x = x->top->father;
    }
    if (x->depth > y->depth) swap(x, y);
    return x - nodes;
  }

  void change(TreeNode * x, TreeNode * y, int k) {
    while (x->top != y->top) {
      if (x->top->depth < y->top->depth) {
        swap(x, y);
      }
      t_.add(x->top->p, x->p, k);
      x = x->top->father;
    }
    if (x->depth > y->depth) {
      swap(x, y);
    }
    t_.add(x->p, y->p, k);
  }

  long long get(TreeNode * x, TreeNode * y) {
    long long res = 0;
    while (x->top != y->top) {
      if (x->top->depth < y->top->depth) {
        swap(x, y);
      }
      res += t_.get(x->top->p, x->p);
      res %= p;
      x = x->top->father;
    }
    if (x->depth > y->depth) {
      swap(x, y);
    }
    res += t_.get(x->p, y->p);
    res %= p;
    return res;
  }
public:
  void init() {
    init1(nodes + root, nullptr);
    init2(nodes + root, nodes + root);
    t_.build(Total);
  }

  int find(int x, int y) {
    return find(x + nodes, y + nodes);
  }

  void change(int x, int k) {
    t_.add(nodes[x].p, nodes[x].p + nodes[x].size - 1, k);
  }

  long long get(int x) {
    return t_.get(nodes[x].p, nodes[x].p + nodes[x].size - 1) % p;
  }

  int get(int x, int y) {
    return get(nodes + x, nodes + y);
  }

  void change(int x, int y, int k) {
    change(nodes + x, nodes + y, k);
  }
}t;

int main() {
  cin >> n >> m >> root >> p;
  g.init(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g.add(x, y, 0);
    g.add(y, x, 0);
  }
  t.init();
  for (int i = 1; i <= n; i++) {
    t.change(i, i, a[i]);
  }
  while (m--) {
    int opt;
    int x, y, z;
    cin >> opt >> x;
    if (opt == 1) {
      cin >> y >> z;
      t.change(x, y, z);
    } else if (opt == 2) {
      cin >> y;
      cout << t.get(x, y) << endl;
    } else if (opt == 3) {
      cin >> y;
      t.change(x, y);
    } else {
      cout << t.get(x) << endl;
    }
  }
  return 0;
}

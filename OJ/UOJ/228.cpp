#include <cmath>
#include <iostream>
#define int long long

using namespace std;

const int kMaxN = 1e6;

class SegmentTree {
private:
  struct node {
    int l, r;
    int value;
    int max, min;
    int lazy = 0;
    node *left, *right;

    void add(int x) {
      lazy += x;
      max += x;
      min += x;
      value += (r - l + 1) * x;
    }

    void pushdown() {
      if (lazy == 0) return;
      left->add(lazy);
      right->add(lazy);
      lazy = 0;
    }

    void pushup() {
      max = std::max(left->max, right->max);
      min = std::min(left->min, right->min);
      value = left->value + right->value;
    }
  } * root;

  void build(node* p, int* a, int l, int r) {
    p->l = l, p->r = r;
    if (l == r) {
      p->value = p->max = p->min = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p->left = new node, a, l, mid);
    build(p->right = new node, a, mid + 1, r);
    p->pushup();
  }

  void sqrt(node* p, int l, int r) {
    if (p->l > r || p->r < l) {
      return;
    }
    if (l <= p->l && p->r <= r) {
      int a = std::sqrt(p->max), b = std::sqrt(p->min);
      if (p->max == p->min) {
        p->add(a - p->max);
        return;
      }
      if (p->max - a == p->min - b) {
        p->add(a - p->max);
        return;
      }
    }
    p->pushdown();
    sqrt(p->left, l, r);
    sqrt(p->right, l, r);
    p->pushup();
  }

  void add(node *p, int l, int r, int k) {
    if (p->l > r || p->r < l) {
      return;
    }
    if (p->l >= l && p->r <= r) {
      p->add(k);
      return;
    }
    p->pushdown();
    add(p->left, l, r, k);
    add(p->right, l, r, k);
    p->pushup();
  }

  int get(node* p, int l, int r) {
    if (p->l > r || p->r < l) {
      return 0;
    }
    if (l <= p->l && p->r <= r) {
      return p->value;
    }
    p->pushdown();
    return get(p->left, l, r) + get(p->right, l, r);
  }

public:
  void build(int* a, int n)     { build(root = new node, a, 1, n); }
  int get(int l, int r)         { return get(root, l, r); }
  void add(int l, int r, int k) { add(root, l, r, k); }
  void sqrt(int l, int r)       { sqrt(root, l, r); }
}t;

int a[kMaxN];

signed main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  t.build(a, n);
  for (int i = 1; i <= m; i++) {
    int opt, l, r;
    cin >> opt >> l >> r;
    if (opt == 1) {
      int x;
      cin >> x;
      t.add(l, r, x);
    } else if (opt == 2) {
      t.sqrt(l, r);
    } else {
      cout << t.get(l, r) << endl;
    }
  }
  return 0;
}

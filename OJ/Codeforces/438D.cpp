#include <algorithm>
#include <iostream>
#define int long long

using namespace std;

const int kMaxN = 1e6;

class SegmentTree {
private:
  struct node {
    int l, r;
    int value;
    int max = 0;
    node * left, * right;

    void pushup() {
      value = left->value + right->value;
      max = std::max(left->max, right->max);
    }
  } * root;

  void build(node * p, int * a, int l, int r) {
    p->l = l, p->r = r;
    if (l == r) {
      p->value = p->max = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p->left = new node, a, l, mid);
    build(p->right = new node, a, mid + 1, r);
    p->pushup();
  }

  void add(node * p, int x, int k) {
    if (p->l == x && p->r == x) {
      p->value = p->max = k;
      return;
    }
    if (p->l > x || p->r < x) {
      return;
    }
    add(p->left, x, k);
    add(p->right, x, k);
    p->pushup();
  }

  void change(node * p, int l, int r, int k) {
    if (p->max < k) { return; }
    if (p->l > r || p->r < l) { return; }
    if (p->l == p->r) {
      p->value = p->max = p->value % k;
      return;
    }
    change(p->left, l, r, k);
    change(p->right, l, r, k);
    p->pushup();
  }

  int get(node * p, int l, int r) {
    if (l <= p->l && p->r <= r) {
      return p->value;
    }
    if (p->l > r || p->r < l) {
      return 0;
    }
    return get(p->left, l, r) + get(p->right, l, r);
  }

public:
  void add(int x, int k)          { add(root, x, k); }
  void build(int n, int * a)      { build(root = new node, a, 1, n); }
  void change(int l, int r,int k) { change(root, l, r, k); }
  int  get(int l, int r)          { return get(root, l, r); }
}tree;

int n, m;
int a[kMaxN];

signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  tree.build(n, a);
  for (int i = 1; i <= m; i++) {
    int opt, x, y;
    cin >> opt >> x >> y;
    if (opt == 1) {
      cout << tree.get(x, y) << endl;
    } else if (opt == 2) {
      int z;
      cin >> z;
      tree.change(x, y, z);
    } else if (opt == 3) {
      tree.add(x, y);
    }
  }
  return 0;
}

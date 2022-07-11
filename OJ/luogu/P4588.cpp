#include <iostream>
#define int unsigned long long

using namespace std;

class SegmentTree {
private:
  int MOD;

  struct node {
    int value;
    int l, r;
    node * left, * right;
  } * root;

  void pushup(node * p) {
    p->value = p->left->value * p->right->value % MOD;
  }

  void change(node * p, int x, int v) {
    if (p->l > x || p->r < x) {
      return;
    }
    if (p->l == x && p->r == x) {
      p->value = v;
      return;
    }
    change(p->left, x, v);
    change(p->right, x, v);
    pushup(p);
  }

  void build(node * p, int l, int r) {
    p->l = l, p->r = r;
    if (l == r) {
      p->value = 1;
      return;
    }
    int mid = (l + r) >> 1;
    build(p->left = new node, l, mid);
    build(p->right = new node, mid + 1, r);
    pushup(p);
  }

  int ask(node * p, int l, int r, int MOD) {
    if (p->l > r || p->r < l) {
      return 1;
    }
    if (l <= p->l && p->r <= r) {
      return p->value % MOD;
    }
    return ask(p->left, l, r, MOD) * ask(p->right, l, r, MOD) % MOD;
  }
public:
  void build(int n, int MOD) { build(root = new node, 1, n); this->MOD = MOD; }
  void change(int x, int v) { change(root, x, v); }
  int ask() { return root->value; }
};

int q, M;

void solve() {
  SegmentTree tree;
  cin >> q >> M;
  tree.build(q, M);
  for (int i = 1; i <= q; i++) {
    int opt, x;
    cin >> opt >> x;
    if (opt == 1) {
      tree.change(i, x);
    } else {
      tree.change(x, 1);
    }
    cout << tree.ask() << endl;
  }
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

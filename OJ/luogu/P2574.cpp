#include <iostream>

using namespace std;

const int kMaxN= 1e6;

class SegmentTree {
private:
  struct node {
    int value;
    int lazy;
    int l, r;
    node * left, * right;

    void change() {
      lazy ^= 1;
      value = (r - l + 1) - value;
    }

    void pushdown() {
      if (lazy) {
        lazy ^= 1;
        left->change();
        right->change();
      }
    }

    void pushup() {
      value = left->value + right->value;
    }
  } * root;

  void build(node * p, int * array, int l, int r) {
    p->l = l, p->r = r;
    if (l == r) {
      p->value = p->lazy = array[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p->left = new node, array, l, mid);
    build(p->right = new node, array, mid + 1, r);
    p->pushup();
  }

  void change(node * p, int l, int r) {
    if (p->l > r || p->r < l) {
      return;
    }
    if (l <= p->l && p->r <= r) {
      p->change();
      return;
    }
    p->pushdown();
    change(p->left, l, r);
    change(p->right, l, r);
    p->pushup();
  }

  int get(node * p, int l, int r) {
    if (p->l > r || p->r < l) {
      return  0;;
    }
    if (l <= p->l && p->r <= r) {
      return p->value;
    }
    p->pushdown();
    return get(p->left, l, r) + get(p->right, l, r);
  }

public:
  int get(int l, int r) { return get(root, l, r); }
  void change(int l, int r) { change(root, l, r); };
  void build(int * array, int n) { build(root = new node, array, 1, n); }
}tree;

int n, m;
int a[kMaxN];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    char ch;
    cin >> ch;
    a[i] = ch - '0';
  }
  tree.build(a, n);
  for (int i = 1; i <= m; i++) {
    int opt, l, r;
    cin >> opt >> l >> r;
    if (opt == 0) {
      tree.change(l, r);
    } else {
      cout << tree.get(l, r) << endl;
    }
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n;

class SegmentTree {
private:
  struct node {
    node *left, *right;
    int l, r;
    int Max, Min;
    int value, lazy;
  } * root;

  void pushdown(node *p) {
    if (p->l == p->r) {
      p->lazy = 0;
      return;
    }
    if (p->lazy) {
      p->left->value += (p->left->r - p->left->l + 1) * p->lazy;
      p->left->Max += p->lazy;
      p->left->Min += p->lazy;
      p->left->lazy += p->lazy;
      p->right->value += (p->right->r - p->right->l + 1) * p->lazy;
      p->right->Max += p->lazy;
      p->right->Min += p->lazy;
      p->right->lazy += p->lazy;
    }
    p->lazy = 0;
  }

  void update(node *p) {
    p->Max = max(p->left->Max, p->right->Max);
    p->Min = min(p->left->Min, p->right->Min);
    p->value = p->left->value + p->right->value;
  }

  void update(node *p, int k) {
    if (p->Max < k) {
      return;
    }
    pushdown(p);
    if (p->Min >= k) {
      add(p->l, p->r, 1);
      return;
    }
    update(p->left, k);
    update(p->right, k);
    update(p);
  }

  void build(node *p, int l, int r) {
    if (l > r) return;
    p->l = l, p->r = r;
    if (l == r) {
      return;
    }
    int mid = l + ((r - l) >> 1);
    build(p->left = new node, l, mid);
    build(p->right = new node, mid + 1, r);
    update(p);
  }

  void add(node *p, int l, int r, int k) {
    if (l > p->r || p->l > r) {
      return;
    }
    pushdown(p);
    if (l <= p->l && p->r <= r) {
      p->value += (p->r - p->l + 1) * k;
      p->lazy += k;
      p->Max += k;
      p->Min += k;
      return;
    }
    add(p->left, l, r, k);
    add(p->right, l, r, k);
    update(p);
  }

  int get(node *p, int l, int r) {
    if (l > p->r || p->l > r) {
      return 0;
    }
    pushdown(p);
    if (l <= p->l && p->r <= r) {
      return p->value;
    }
    return get(p->left, l, r) + get(p->right, l, r);
  }

public:
  void add(int l, int r, int k) { add(root, l, r, k); }

  int get(int l, int r) { return get(root, l, r); }

  void update(int k) { update(root, k); }

  void build(int n) { build(root = new node, 1, n); }
} tree;

int main() {
  cin >> n;
  tree.build(n);
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    tree.update(k + 1);
    tree.add(i, i, k + 1);
  }
  for (int i = 1; i <= n; i++) {
    // cout << tree.get(i, i) << " ";
  }
  return 0;
}

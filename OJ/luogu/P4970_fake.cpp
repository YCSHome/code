#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

class SegmentTree {
private:
  struct node {
    int value, max;
    node * left, * right;
    int l, r;
    int add, clear;
    node() {
      left = right = nullptr;
    }
  }*root;

  void pushup(node* p) {
    p->add = p->clear = 0;
    p->value = p->left->value + p->right->value;
    p->max = max(p->left->max, p->right->max);
  }

  void pushdown(node* p) {
    if (p->left || p->right) {
      if (p->clear) {
        p->left->value = p->right->value = 0;
        p->left->add = p->right->add = 0;
        p->left->max = p->right->max = 0;
        p->left->clear = p->right->clear = 1;
      } else {
        p->left->value += p->add * (p->left->r - p->left->l + 1);
        p->left->max += p->add;
        p->left->add += p->add;
        p->right->value += p->add * (p->right->r - p->right->l + 1);
        p->right->max += p->add;
        p->right->add += p->add;
      }

      p->add = 0;
      p->clear = 0;
    }
  }

  void build(node* p, int l, int r, int *a) {
    p->l = l, p->r = r;
    if (l == r) {
      p->value = (a == nullptr ? 0 : a[l]);
      p->max = p->value;
      return;
    }
    int mid = (l + r) >> 1;
    build(p->left = new node, l, mid, a);
    build(p->right = new node, mid + 1, r, a);
    pushup(p);
  }

  int get_sum(node* p, int l, int r) {
    if (l <= p->l && p->r <= r) { return p->value; }
    if (l > p->r || p->l > r)   { return 0; }
    pushdown(p);
    return get_sum(p->left, l, r) + get_sum(p->right, l, r);
  }

  int get_max(node* p, int l, int r) {
    if (l <= p->l && p->r <= r) { return p->max; }
    if (l > p->r || p->l > r)   { return 0; }
    pushdown(p);
    return max(get_max(p->left, l, r), get_max(p->right, l, r));
  }

  void add(node* p, int l, int r, int k) {
    if (l > p->r || p->l > r) { return; }
    pushdown(p);
    if (l <= p->l && p->r <= r) {
      p->add += k;
      p->value += (p->r - p->l + 1) * k;
      p->max += k;
      return;
    }
    add(p->left, l, r, k);
    add(p->right, l, r, k);
    pushup(p);
  }

  void clear(node* p, int l, int r) {
    if (l > p->r || p->l > r) { return; }
    pushdown(p);
    if (l <= p->l && p->r <= r) {
      p->value = p->max = p->add = 0;
      p->clear = 1;
      return;
    }
    clear(p->left, l, r);
    clear(p->right, l, r);
    pushup(p);
  }
public:
  void build(int n)         { build(root = new node, 1, n, nullptr); }
  void build(int *a, int n) { build(root = new node, 1, n, a); }

  void clear(int l, int r)      { clear(root, l, r); }
  void add(int l, int r, int k) { add(root, l, r, k); }
  int  get_sum(int l, int r)    { return get_sum(root, l, r); }
  int  get_max(int l, int r)    { return get_max(root, l, r); }
}tree1, tree2;

int n, m;
int a[MAXN];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  tree1.build(a, n);
  tree2.build(n);
  int ans = 0;
  while (m--) {
  }
  return 0;
}

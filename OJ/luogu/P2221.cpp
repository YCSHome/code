#include <iostream>
#define int long long

using namespace std;

const int kMaxN = 1e6;

long long a1[kMaxN];
long long a2[kMaxN];

class SegmentTree {
private:
  struct node {
    node * left, * right;
    int l, r;
    int lazy = 0;
    int value1, value2, value3;

    void pushdown() {
      if (left == nullptr) return;
      left->add(lazy);
      right->add(lazy);
      lazy = 0;
    }

    void pushup() {
      value1 = left->value1 + right->value1;
      value2 = left->value2 + right->value2;
      value3 = left->value3 + right->value3;
    }

    void add(int x) {
      lazy += x;
      value1 += (r - l + 1) * x;
      value2 += (a1[r] - a1[l - 1]) * x;
      value3 += (a2[r] - a2[l - 1]) * x;
    }
  } * root;

  void build(node * p, int l, int r) {
    p->l = l;
    p->r = r;
    if (p->l == p->r) { return; }
    int mid = (r + l) >> 1;
    build(p->left = new node, l, mid);
    build(p->right = new node, mid + 1, r);
  }

  void add(node * p, int l, int r, int k) {
    if (p->l > r || p->r < l) {
      return;
    }
    if (l <= p->l && p->r <= r) {
      p->add(k);
      return;
    }
    p->pushdown();
    add(p->left, l, r, k);
    add(p->right, l, r, k);
    p->pushup();
  }

  int getV1(node * p, int l, int r) {
    if (p->l > r || p->r < l) { return 0; }
    if (l <= p->l && p->r <= r) {
      return p->value1;
    }
    p->pushdown();
    return getV1(p->left, l, r) + getV1(p->right, l, r);
  }

  int getV2(node * p, int l, int r) {
    if (p->l > r || p->r < l) { return 0; }
    if (l <= p->l && p->r <= r) {
      return p->value2;
    }
    p->pushdown();
    return getV2(p->left, l, r) + getV2(p->right, l, r);
  }

  int getV3(node * p, int l, int r) {
    if (p->l > r || p->r < l) { return 0; }
    if (l <= p->l && p->r <= r) {
      return p->value3;
    }
    p->pushdown();
    return getV3(p->left, l, r) + getV3(p->right, l, r);
  }

public:
  void build(int n)             { build(root = new node, 1, n); }
  void add(int l, int r, int k) { add(root, l, r, k); }
  int getV1(int l, int r)       { return getV1(root, l, r); }
  int getV2(int l, int r)       { return getV2(root, l, r); }
  int getV3(int l, int r)       { return getV3(root, l, r); }
}tree;

int n, m;

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

signed main() {
  for (int i = 1; i < kMaxN; i++) {
    a1[i] = i + a1[i - 1];
    a2[i] = i * i + a2[i - 1];
  }
  cin >> n >> m;
  tree.build(n);
  for (int i = 1; i <= m; i++) {
    char op;
    int l, r;
    cin >> op >> l >> r;
    if (op == 'C') {
      int v;
      cin >> v;
      tree.add(l, r - 1, v);
    } else {
      int s1 = tree.getV1(l, r - 1);
      int s2 = tree.getV2(l, r - 1);
      int s3 = tree.getV3(l, r - 1);
      int a = (-s3 + (r + l - 1) * s2 - r * (l - 1) * s1);
      r--;
      int b = (r - l + 2) * (r - l + 1) / 2;
      int t = gcd(a, b);
      cout << (a / t) << "/" << (b / t) << endl;
    }
  }
  return 0;
}

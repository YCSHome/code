#include <cmath>
#include <iostream>
#define int unsigned long long

using namespace std;
const int P = 131;
const int MOD = 1e9 + 7;
const int kMaxN = 3e5 + 100;

int p[kMaxN];

template <int type>
class SegmentTree {
private:
  struct node {
    int l = 0, r = 0;
    int value = 0;
    node *left, *right;

    node merge(node a, node b);

    void pushup() { value = merge(*left, *right).value; }
  } * root;

  void change(node* p, int x, int k) {
    if (p->l > x || p->r < x) return;
    if (p->l == p->r) {
      p->value = k;
      return;
    }
    change(p->left, x, k);
    change(p->right, x, k);
    p->pushup();
  }

  void build(node* p, int l, int r) {
    p->l = l, p->r = r;
    if (l == r) {
      p->left = p->right = nullptr;
      p->value = 0;
      return;
    }
    int mid = (l + r) >> 1;
    build(p->left = new node, l, mid);
    build(p->right = new node, mid + 1, r);
    p->pushup();
  }

  node get(node* p, int l, int r) {
    if (l <= p->l && p->r <= r) {
      return *p;
    }
    int mid = (p->l + p->r) >> 1;
    if (r <= mid) {
      return get(p->left, l, r);
    }
    if (mid < l) {
      return get(p->right, l, r);
    }
    return p->merge(get(p->left, l, r), get(p->right, l, r));
  }

public:
  void build(int n) { build(root = new node, 1, n); }
  int get(int l, int r) { return get(root, l, r).value; }
  void change(int x, int k) { change(root, x, k); }
};

template <>
SegmentTree<0>::node SegmentTree<0>::node::merge(node a, node b) {
  node temp;
  temp.l = a.l, temp.r = b.r;
  temp.value = a.value * p[b.r - b.l + 1] % MOD + b.value;
  return temp;
}

template <>
SegmentTree<1>::node SegmentTree<1>::node::merge(node a, node b) {
  node temp;
  temp.l = a.l, temp.r = b.r;
  temp.value = b.value * p[a.r - a.l + 1] % MOD + a.value;
  return temp;
}

int n;
int a[kMaxN];
SegmentTree<0> t1;
SegmentTree<1> t2;

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] * P;
    p[i] %= MOD;
  }
  t1.build(n);
  t2.build(n);
  for (int i = 1; i <= n; i++) {
    t1.change(a[i], 1);
    t2.change(a[i], 1);
    int k = min(a[i] - 1, n - a[i]);
    if (k <= 0) continue;
    if (t1.get(a[i] - k, a[i] - 1) != t2.get(a[i] + 1, a[i] + k)) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}

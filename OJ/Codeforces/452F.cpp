#include <cmath>
#include <iostream>
#define int unsigned long long

using namespace std;
const int P = 131;
const int kMaxN = 3e5 + 100;

int p[kMaxN];

class SegmentTree {
private:
  struct node {
    int len = 0;
    int l = 0, r = 0;
    int value1 = 0, value2 = 0;
    node *left, *right;

    friend node merge(node a, node b) {
      node temp;
      temp.len = a.len + b.len;
      temp.value1 = (a.value1 * p[b.len] + b.value1);
      temp.value2 = (b.value2 * p[a.len] + a.value2);
      return temp;
    }

    void pushup() {
      node temp = merge(*left, *right);
      this->len = temp.len;
      this->value1 = temp.value1;
      this->value2 = temp.value2;
    }
  } * root;

  void change(node* p, int x, int k) {
    if (p->l > x || p->r < x) return;
    if (p->l == p->r) {
      p->value1 = p->value2 = k;
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
      p->len = 1;
      return;
    }
    int mid = (l + r) >> 1;
    build(p->left = new node, l, mid);
    build(p->right = new node, mid + 1, r);
    p->pushup();
  }

  node get1(node* p, int l, int r) {
    if (l <= p->l && p->r <= r) {
      return *p;
    }
    int mid = (p->l + p->r) >> 1;
    if (r <= mid) {
      return get1(p->left, l, r);
    }
    if (mid < l) {
      return get1(p->right, l, r);
    }
    return merge(get1(p->left, l, r), get1(p->right, l, r));
  }

  node get2(node* p, int l, int r) {
    if (l <= p->l && p->r <= r) {
      return *p;
    }
    int mid = (p->l + p->r) >> 1;
    if (r <= mid) {
      return get2(p->left, l, r);
    }
    if (mid < l) {
      return get2(p->right, l, r);
    }
    return merge(get2(p->left, l, r), get2(p->right, l, r));
  }

  void print(node * p) {
    if (p == nullptr) return;
    print(p->left);
    print(p->right);
  }

public:
  void build(int n) { build(root = new node, 1, n); }
  int get1(int l, int r) { return get1(root, l, r).value1; }
  int get2(int l, int r) { return get2(root, l, r).value2; }
  void change(int x, int k) { change(root, x, k); }
  void print() {
    print(root);
  }
}t;

int n;
int a[kMaxN];

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] * P;
  }
  t.build(n);
  for (int i = 1; i <= n; i++) {
    t.change(a[i], 1);
    int k = min(a[i] - 1, n - a[i]);
    if (k <= 0) continue;
    if (t.get1(a[i] - k, a[i] - 1) != t.get2(a[i] + 1, a[i] + k)) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}

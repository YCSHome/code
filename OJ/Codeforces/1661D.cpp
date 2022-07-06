#include <iostream>
#include <cmath>
#define int long long

using namespace std;

const int kMaxN = 1e6;

class SegmentTree {
private:
  struct node {
    int value, l, r;
    int lazy_tag;
    node * left, * right;
    node(int l, int r) : l(l), r(r) {
      left = right = nullptr;
      lazy_tag = 0;
    }

    void add(int v) {
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

  int get(node * p, int l, int r) {
    if (p->r < l || p->l > r) {
      return 0;
    }
    if (p->l >= l && p->r <= r) {
      return p->value;
    }
    pushdown(p);
    return get(p->left, l, r) + get(p->right, l, r);
  }

  void build(node * p, int * array, int l, int r) {
    if (l == r) {
      p->value = array[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p->left = new node(l, mid), array, l, mid);
    build(p->right = new node(mid + 1, r), array, mid + 1, r);
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
  void build(int * array, int n) { build(root = new node(1, n), array, 1, n); }
  void add(int l, int r, int k)  { add(root, l, r, k); }
  int  get(int l, int r)         { return get(root, l, r); }
};

int n;
int k;
int a[kMaxN];
int b[kMaxN];
SegmentTree tree;
// 毁灭吧，赶紧的

signed main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    a[i] = -b[i] + b[i - 1];
  }
  tree.build(a, n);
  int tot = 0, ans = 0;;
  for (int i = n; i >= 1; i--) {
    int temp = tree.get(1, i);
    if (temp < 0) {
      temp = -temp;
      if (i >= k) {
        int t = ceil((double)temp / k);
        tree.add(i - k + 1, i, t);
        ans += t;
      } else {
        int t = ceil((double)temp / i);
        tree.add(1, k, t);
        ans += t;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

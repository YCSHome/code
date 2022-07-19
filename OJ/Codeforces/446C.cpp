#include <iostream>
#define int long long

using namespace std;

const int MOD = 1e9 + 9;
const int kMaxN = 2e6;

long long f[kMaxN];

class SegmentTree {
private:
  struct node {
    int l = 0, r = 0;
    int lazyA = 0, lazyB = 0;
    int value = 0;
    node * left, * right;

    void add(int a, int b) {
      lazyA += a;
      lazyA %= MOD;
      lazyB += b;
      lazyB %= MOD;
      value += a * f[r - l + 1] % MOD + b * f[r - l + 1 + 1] % MOD - b;
      value %= MOD;
    }

    void pushup() {
      value = left->value + right->value;
    }

    void pushdown() {
      if (!lazyA) {
        return;
      }
      // 左右儿子要区别对待
      left->add(lazyA, lazyB);
      int leftLen = left->r - left->l + 1;
      right->add((lazyA * f[leftLen  - 1] % MOD + lazyB * f[leftLen] % MOD) % MOD,
                  lazyA * f[leftLen] % MOD + lazyB * f[leftLen + 1] % MOD);
      lazyA = lazyB = 0;
    }
  } * root;

  void build(node * p, int * a, int l, int r) {
    p->l = l, p->r = r;
    if (l == r) {
      p->value = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p->left = new node, a, l, mid);
    build(p->right = new node, a, mid + 1, r);
    p->pushup();
  }

  int get(node * p, int l, int r) {
    if (p->l > r || p->r < l) return 0;
    if (l <= p->l && p->r <= r) {
      return p->value;
    }
    p->pushdown();
    return (get(p->left, l, r) + get(p->right, l, r)) % MOD;
  }

  void change(node * p, int l, int r) {
    if (p->l > r || p->r < l) { return; }
    if (l <= p->l && p->r <= r) {
      p->add(f[p->l - l + 1], f[p->l - l + 2]);
      return;
    }
    p->pushdown();
    change(p->left, l, r);
    change(p->right, l, r);
    p->pushup();
  }

public:
  void build(int * a, int n) { build(root = new node, a, 1, n); }
  int get(int l, int r)      { return get(root, l, r); }
  void change(int l, int r)  { change(root, l, r); }
}t;

int n, m;
int a[kMaxN];

signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  f[1] = 1;
  for (int i = 2; i < kMaxN - 10; i++) { f[i] = (f[i - 2] + f[i - 1]) % MOD; }
  t.build(a, n);
  for (int i = 1; i <= m; i++) {
    int opt, l, r;
    cin >> opt >> l >> r;
    if (opt == 1) {
      t.change(l, r);
    } else {
      cout << (t.get(l, r) + MOD) % MOD << endl;
    }
  }
  return 0;
}

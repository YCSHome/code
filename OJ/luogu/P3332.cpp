#include <ios>
#include <iostream>
#define int long long

using namespace std;

const int kMaxN = 1e6;

class SegmentTree {
private:
  struct node {
    int l, r;
    int lazy = 0;
    int _clear = 0;
    int value = 0;
    node * left, * right;

    void clear() {
      _clear = 1;
      value = 0;
      lazy = 0;
    }

    void add(int x) {
      lazy += x;
      value += (r - l + 1) * x;
    }

    void pushdown() {
      if (_clear == 1) {
        left->clear();
        right->clear();
        _clear = 0;
      }
      if (lazy != 0) {
        left->add(lazy);
        right->add(lazy);
        lazy = 0;
      }
    }

    void pushup() {
      value = left->value + right->value;
    }
  } * root;

  void build(node * p, int l, int r) {
    p->l = l, p->r = r;
    if (l == r) {
      return;
    }
    int mid = (l + r) >> 1;
    build(p->left = new node, l, mid);
    build(p->right = new node, mid + 1, r);
  }

  void add(node * p, int l, int r, int k) {
    if (p->r < l || p->l > r) {
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

  int get(node * p, int l, int r) {
    if (p->r < l || p->l > r) {
      return 0;
    }
    if (l <= p->l && p->r <= r) {
      return p->value;
    }
    p->pushdown();
    return get(p->left, l, r) + get(p->right, l, r);
  }

public:
  void add(int l, int r, int k) { add(root, l, r, k); }
  void build(int n) { build(root = new node, 1, n); }
  int get(int l, int r)         { return get(root, l, r); }
  void clear() { root->clear(); }
}t;

struct q {
  int type, l, r, c;
  int id;
}a[kMaxN], templ[kMaxN], tempr[kMaxN];

int n, m;
int ans[kMaxN];

void solve(int l, int r, int valueLeft, int valueRight) {
  if (l > r) return;
  if (valueLeft == valueRight) {
    for (int i = l; i <= r; i++) {
      if (a[i].type == 2) {
        ans[a[i].id] = valueLeft;
      }
    }
    return;
  }
  bool left = false, right = false;
  int cnt1 = 0, cnt2 = 0;
  int mid = (valueLeft + valueRight) >> 1;
  t.clear();
  for (int i = l; i <= r; i++) {
    if (a[i].type == 1) {
      if (a[i].c > mid) {
        t.add(a[i].l, a[i].r, 1);
        tempr[++cnt2] = a[i];
      } else {
        templ[++cnt1] = a[i];
      }
    } else {
      int value = t.get(a[i].l, a[i].r);
      if (value < a[i].c) {
        a[i].c -= value;
        left = true;
        templ[++cnt1] = a[i];
      } else {
        tempr[++cnt2] = a[i];
        right = true;
      }
    }
  }
  for (int i = 1; i <= cnt1; i++) {
    a[l + i - 1] = templ[i];
  }
  for (int i = cnt1 + 1; i <= cnt1 + cnt2; i++) {
    a[l + i - 1] = tempr[i - cnt1];
  }
  if (left) {
    solve(l, l + cnt1 - 1, valueLeft, mid);
  }
  if (right) {
    solve(l + cnt1, r, mid + 1, valueRight);
  }
}

signed main() {
  cin >> n >> m;
  int qCnt = 0;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].type >> a[i].l >> a[i].r >> a[i].c;
    if (a[i].type == 2) {
      a[i].id = ++qCnt;
    }
  }
  t.build(n);
  solve(1, m, -1e9, 1e9);
  for (int i = 1; i <= qCnt; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int kMaxN = 1e6;

class SegmentTree {
private:
  struct node {
    int value;
    int l, r;
    node * left, * right;

    void pushup() {
      value = max(this->right->value, this->left->value);
    }
  } * root;

  void build(node * p, int l, int r) {
    p->l = l, p->r = r;
    if (l == r) {
      p->value = 0;
      return;
    }
    int mid = (l + r) >> 1;
    build(p->left = new node, l, mid);
    build(p->right = new node, mid + 1, r);
  }

  void set(node * p, int x, int k) {
    if (p->r < x || p->l > x) {
      return;
    }
    if (p->r == x && p->l == x) {
      p->value = k;
      return;
    }
    set(p->left, x, k);
    set(p->right, x, k);
    p->pushup();
  }

  int get(node * p, int l, int r) {
    if (p->l > r || p->r < l) {
      return -1e9 - 1000;
    }
    if (l <= p->l && p->r <= r) {
      return p->value;
    }
    return max(get(p->left, l, r), get(p->right, l, r));
  }

public:
  int get(int l, int r) { return get(root, l ,r); }
  void set(int x, int k) { set(root, x, k); }
  void build(int n) { build(root = new node, 1, n); }
}tree;

int n, year[kMaxN];
int rain[kMaxN];
int temp[kMaxN];
map<int, bool> know;

int main() {
  cin >> n;
  tree.build(n + 10);
  for (int i = 1; i <= n; i++) {
    cin >> year[i] >> rain[i];
    know[year[i]] = true;
  }
  sort(temp + 1, temp + 1 + n);
  for (int i = 1; i <= n; i++) {
    tree.set(i, rain[i]);
  }
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    if (a >= b) {
      cout << "false" << endl;
      continue;
    }
    int u = lower_bound(year + 1, year + 1 + n, a) - year;
    int v = lower_bound(year + 1, year + 1 + n, b) - year;
    bool A = know[a], B = know[b];
    if (!A) {
      u--;
    }
    int max = 0;
    if (u + 1 <= v - 1) {
      max = tree.get(u + 1, v - 1);
    }
    if ((max >= rain[v] && B) || (rain[u] < rain[v] && A && B) || (max >= rain[u] && A)) {
      cout << "false" << endl;
    } else if (v - u != year[v] - year[u] || !A || !B) {
      cout << "maybe" << endl;
    } else {
      cout << "true" << endl;
    }
  }
  return 0;
}

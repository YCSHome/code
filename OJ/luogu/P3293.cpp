#include <iostream>
#include <algorithm>

using namespace std;

const int kMaxN = 1e6;

class SegmentTree {
private:
  struct node {
    int l, r;
    node *left, *right;
  };

  void build(node * p, int l, int r) {
    p->l = l, p->r = r;
    if (l == r) {
      return;
    }
  }
public:
};

// 1 3 5 2 4 6

struct q {
  int b, x, l, r;
  bool operator<(const q& cmp) const {
    return r > cmp.r;
  }
}b[kMaxN];

int n, m;
int a[kMaxN];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) { cin >> a[i]; }
  for (int i = 1; i <= m; i++) { cin >> b[i].b >> b[i].x >> b[i].l >> b[i].r; }
  sort(b + 1, b + 1 + m);
  for (int i = 1; i <= m; i++) {
    int _b = b[i].b;
    int x = b[i].x;
    int l = b[i].l;
    int r = b[i].r;
  }
  return 0;
}

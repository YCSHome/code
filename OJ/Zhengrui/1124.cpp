#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <bitset>

using namespace std;

const int kMaxN = 1e6;

bitset<2010> able, temp;
short a[kMaxN];
short b[kMaxN];
short ans[kMaxN];
short n;
int q;

struct q {
  short l, r, s;
  int id = 0;
  bool operator<(const q& cmp) const {
    if (l == cmp.l) {
      return r < cmp.r;
    }
    return l < cmp.l;
  }
}c[kMaxN];

int main() {
  scanf("%hd%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= q; i++) {
    cin >> c[i].l >> c[i].r >> c[i].s;
    c[i].id = i;
  }
  sort(c + 1, c + 1 + q);
  for (int i = 1; i <= q; i++) {
    if (c[i].l != c[i - 1].l) {
      able.reset();
      able[0] = true;
      for (int j = c[i].l; j <= c[i].r; j++) {
        able |= able << a[j];
      }
    } else {
      for (int j = c[i - 1].r + 1; j <= c[i].r; j++) {
        able |= able << a[j];
      }
    }
    ans[c[i].id] = -1;
    for (int j = c[i].s; j <= 2000; j++) {
      if (able[j]) {
        ans[c[i].id] = j;
        break;
      }
    }
  }
  for (int i = 1; i <= q; i++) {
    printf("%hd\n", ans[i]);
  }
  return 0;
}

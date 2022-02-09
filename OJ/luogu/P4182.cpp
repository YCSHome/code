#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

struct line {
  int l, r;
  bool operator<(const line& cmp) const { return l < cmp.l; }
} a[MAXN];

int n, k;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].l >> a[i].r;
  }
  return 0;
}

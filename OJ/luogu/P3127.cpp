#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

struct node {
  int s, p;
  bool operator<(const node& cmp) const { return p < cmp.p; };
} a[MAXN];

struct line {
  int l, r;
  int ls, rs;
} b[MAXN];

int s[MAXN], p[MAXN];
bool ok[MAXN];
int n, ans = 0;

bool solve(int x) {
  int l, r;
  l = r = x;
  while (1 <= l && r <= n) {
    bool flag = false;
    while (b[r].r - b[l].l - 1 >= b[l].ls) {
      l--;
      flag = true;
      if (ok[l]) return true;
    }
    while (b[r].r - b[l].l - 1 >= b[r].rs) {
      r++;
      flag = true;
      if (ok[r]) return true;
    }
    if (!flag) return false;
  }
  return true;
}

int main() {
  cin >> n;
  ok[0] = ok[n] = true;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].s >> a[i].p;
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i < n; i++) {
    b[i] = {a[i].p, a[i + 1].p, a[i].s, a[i + 1].s};
  }
  n--;
  for (int i = 1; i <= n; i++) {
    ok[i] = solve(i);
    ans += (ok[i] ? 0 : b[i].r - b[i].l);
  }
  cout << ans << endl;
  return 0;
}

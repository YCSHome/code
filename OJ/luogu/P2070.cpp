#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

struct node {
  int l, v;
  bool operator<(const node& cmp) const { return l < cmp.l; }
} a[MAXN];

int cnt = 0;
int n, k = 2, now = 0, len;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    char opt;
    cin >> len >> opt;
    int f = opt == 'R' ? 1 : -1;
    a[++cnt] = {now, f};
    a[++cnt] = {now += len * f, -f};
  }
  sort(a + 1, a + 1 + cnt);
  int temp = a[1].v, ans = 0;
  for (int i = 2; i <= cnt; i++) {
    if (temp >= k) {
      ans += a[i].l - a[i - 1].l;
    }
    temp += a[i].v;
  }
  cout << ans;
  return 0;
}

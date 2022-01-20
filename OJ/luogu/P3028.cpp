#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

struct node {
  int l, r;
}a[MAXN];

int n;
int cnt;
int b[MAXN];
int c[MAXN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].l >> a[i].r;
    b[++cnt] = a[i].l;
    b[++cnt] = a[i].r;
  }
  sort(b + 1, b + 1 + cnt);
  int len = unique(b + 1, b + 1 + cnt) - b - 1;
  for (int i = 1; i <= n; i++) {
    int l = lower_bound(b + 1, b + 1 + len, a[i].l) - b;
    int r = lower_bound(b + 1, b + 1 + len, a[i].r) - b;
    c[l]++, c[r + 1]--;
  }
  int ch = 0, ans = 0;
  for (int i = 1; i <= len; i++) {
    ch += c[i];
    ans = max(ans, ch);
  }
  cout << ans << endl;
  return 0;
}

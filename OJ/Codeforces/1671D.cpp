#include <iostream>
#include <cmath>
#define int long long

using namespace std;

const int kMaxN = 1e6;

int a[kMaxN];

void solve() {
  int n, ans = 0, x;
  int s1 = 0, s2 = 0x3f3f3f3f;
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s1 = max(s1, a[i]);
    s2 = min(s2, a[i]);
  }
  for (int i = 1; i < n; i++) {
    ans += abs(a[i] - a[i + 1]);
  }
  if (s1 < x) {
    int t = min(x - a[1], x - a[n]);
    for (int i = 2; i <= n; i++) {
      t = min(t, 2 * x - a[i] - a[i - 1] - abs(a[i] - a[i - 1]));
    }
    ans += t;
  }
  if (s2 > 1) {
    int t = min(a[1] - 1, a[n] - 1);
    for (int i = 2; i <= n; i++) {
      t = min(t, a[i] + a[i - 1] - 2 - abs(a[i] - a[i - 1]));
    }
    ans += t;
  }
  cout << ans << endl;
}
signed main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

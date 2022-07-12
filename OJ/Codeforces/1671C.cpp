#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

const int kMaxN = 1e6;

int a[kMaxN];

int get(int l, int r) {
  return a[r] - a[l - 1];
}

void solve() {
  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  int cost = 0, ans = 0;
  for (int i = n; i >= 1; i--) {
    if (a[i] + cost * i > x) { continue; }
    int t = (x - a[i] - cost * i) / i + 1;
    ans += t * i;
    cost += t;
  }
  cout << ans << endl;
}

signed main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

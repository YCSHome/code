#include <iostream>
#define int long long

using namespace std;

const int kMaxN = 1e6;

int n;
int a[kMaxN];
int b[kMaxN];

void solve() {
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) { cin >> a[i]; }
  for (int i = 1; i <= n; i++) { cin >> b[i]; }
  for (int i = 1; i < n; i++) {
    int S1 = abs(a[i] - a[i + 1]) + abs(b[i] - b[i + 1]);
    int S2 = abs(a[i] - b[i + 1]) + abs(b[i] - a[i + 1]);
    ans += min(S1, S2);
  }
  cout << ans << endl;
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

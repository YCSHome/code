#include <iostream>
#include <cstring>

using namespace std;

const int kMaxN = 1e6;

int v, n, c;
int k[kMaxN];
int m[kMaxN];
int dp[kMaxN];

int main() {
  cin >> v >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> k[i] >> m[i];
  }
  memset(dp, -1, sizeof(dp));
  dp[0] = c;
  for (int i = 1; i <= n; i++) {
    for (int j = 15000; j >= 0; j--) {
      if (j >= m[i]) {
        dp[j] = max(dp[j], dp[j - k[i]] - m[i]);
      }
    }
  }
  int ans = -1;
  for (int j = v; j < kMaxN; j++) { ans = max(ans, dp[j]); }
  if (ans == -1) {
    cout << "Impossible" << endl;
  } else {
    cout << ans;
  }
  return 0;
}

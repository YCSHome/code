#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int n, m;
int ans = 0;
int w[kMaxN], d[kMaxN];
int dp[12881];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> d[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      if (j >= w[i]) {
        dp[j] = max(dp[j], dp[j - w[i]] + d[i]);
      }
      ans = max(ans, dp[j]);
    }
  }
  cout << ans << endl;
  return 0;
}

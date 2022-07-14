#include <iostream>

using namespace std;

const int kMaxN = 2001;
const int MOD = 1e9 + 7;

int n, k;
int dp[kMaxN][kMaxN];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    dp[1][i] = 1;
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; j * k <= n; k++) {
        dp[i][j] += dp[i - 1][j * k];
        dp[i][j] %= MOD;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += dp[k][i];
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}

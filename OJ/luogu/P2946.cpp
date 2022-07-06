#include <iostream>

using namespace std;

const int kMaxN = 1e6;
const int MOD = 1e8;

int n, f;
int r[kMaxN];
int dp[2011][1010];

int main() {
  cin >> n >> f;
  for (int i = 1; i <= n; i++) {
    cin >> r[i];
    r[i] %= f;
    dp[i][r[i]] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < f; j++) {
      dp[i][j] += dp[i - 1][j];
      int last = (j - r[i] + f) % f;
      dp[i][j] += dp[i - 1][last];
      dp[i][j] %= MOD;
    }
  }
  cout << dp[n][0] << endl;
  return 0;
}

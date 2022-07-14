#include <iostream>

using namespace std;

const int kMaxN = 1100;
const int MOD = 10000;

int n, k;
int dp[kMaxN][kMaxN];

int main() {
  cin >> n >> k;
  dp[1][0] = 1;
  for (int i = 2; i <= n; i++) {
    int temp = 0;
    for (int j = 0; j <= k; j++) {
      temp += dp[i - 1][j];
      temp %= MOD;
      dp[i][j] = temp;
      if (j >= i - 1) {
        temp -= dp[i - 1][j - i + 1];
        temp %= MOD;
        temp += MOD;
        temp %= MOD;
      }
    }
  }
  cout << dp[n][k] << endl;
  return 0;
}

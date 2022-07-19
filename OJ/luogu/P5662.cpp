#include <iostream>
#include <cstring>

using namespace std;

const int kMaxN = 200;

int dp[114514];
int t, n, m;
int cost[kMaxN][kMaxN];

int main() {
  cin >> t >> n >> m;
  for (int i = 1; i <= t; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> cost[i][j];
    }
  }
  for (int i = 1; i < t; i++) {
    memset(dp, 0, sizeof(dp));
    for (int j = 1; j <= n; j++) {
      for (int k = cost[i][j]; k <= m; k++) {
        dp[k] = max(dp[k], dp[k - cost[i][j]] + cost[i + 1][j] - cost[i][j]);
      }
    }
    m += dp[m];
  }
  cout << m << endl;
  return 0;
}

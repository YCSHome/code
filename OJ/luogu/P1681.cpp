#include <iostream>

using namespace std;

const int kMaxN = 1600;

int n, m;
int a[kMaxN][kMaxN];
int dp[kMaxN][kMaxN][2];
int ans = 0;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 0) {
        dp[i][j][0] = min(dp[i - 1][j][1], min(dp[i][j- 1][1], dp[i - 1][j - 1][0]))  + 1;
        ans = max(ans, dp[i][j][0]);
      } else {
        dp[i][j][1] = min(dp[i - 1][j][0], min(dp[i][j- 1][0], dp[i - 1][j - 1][1]))  + 1;
        ans = max(ans, dp[i][j][1]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}

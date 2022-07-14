#include <iostream>
#include <cmath>

using namespace std;

const int kMaxN = 1e6;

int t;
int ans[kMaxN];
int dp[5][114514];

void solve() {
  int n, ans = 0;
  cin >> n;
  for (int i = 1; i <= 4; i++) ans += dp[i][n];
  cout << ans << endl;
}

int main() {
  dp[0][0] = 1;
  for (int i = 1; i * i <= 114514; i++) {
    for (int j = i * i; j <= 114514; j++) {
      for (int k = 1; k <= 4; k++) {
        dp[k][j] += dp[k - 1][j - i * i];
      }
    }
  }
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

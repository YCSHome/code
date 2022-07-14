#include <iostream>

using namespace  std;

const int kMaxN = 2100;

int dp[kMaxN][kMaxN];
int Max[kMaxN];
int n, h, delta;

int main() {
  cin >> n >> h >> delta;
  for (int i = 1; i <= n; i++) {
    int t, x;
    cin >> t;
    while (t--) {
      cin >> x;
      dp[x][i]++;
    }
  }
  for (int i = h; i >= 1; i--) {
    for (int j = 1; j <= n; j++) {
      int t = dp[i + 1][j];
      if (i + delta <= h) {
        t = max(t, Max[i + delta]);
      }
      dp[i][j] += t;
      Max[i] = max(Max[i], dp[i][j]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[1][i]);
  }
  cout << ans << endl;
  return 0;
}

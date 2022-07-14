#include <iostream>
#include <map>

using namespace std;

const int kMaxN = 1e6;
const int MOD = 1e5 + 3;

int n, m;
int dp[kMaxN];
map<int, bool> has[kMaxN];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    has[x][y] = true;
  }
  dp[1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (has[i][j]) {
        dp[j] = 0;
      } else if (!has[i][j - 1]) {
        dp[j] += dp[j - 1];
      }
      dp[j] %= MOD;
    }
  }
  cout << dp[n] << endl;
  return 0;
}

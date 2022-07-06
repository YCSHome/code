#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

const int kMaxN = 1e3 + 10;

int n, m;
vector<pair<int, int>> thing[kMaxN];
int dp[kMaxN][kMaxN], ans = 0;
int Max;

int main() {
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    thing[c].push_back(make_pair(a, b));
    Max = max(Max, c);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = dp[i - 1][j];
      for (const auto& t : thing[i]) {
        if (j - t.first >= 0) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - t.first] + t.second);
        }
      }
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}

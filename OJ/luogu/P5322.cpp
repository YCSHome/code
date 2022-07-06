#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int kMaxN = 1e6;

int s, n, m;
int a[200][200];
vector<int> cost[200];
int value[200][200];
int dp[200][21001];
int ans = 0;

int main() {
  cin >> s >> n >> m;
  for (int i = 1; i <= s; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      cost[j].push_back(a[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    cost[i].push_back(0);
    sort(cost[i].begin(), cost[i].end());
    for (int j = 1; j < cost[i].size(); j++) {
      cost[i][j] = cost[i][j] * 2 + 1;
      value[i][j] = value[i][j - 1] + i;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i][j] = dp[i - 1][j];
      for (int k = 1; k < cost[i].size(); k++) {
        if (cost[i][k] <= j) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i][k]] + value[i][k]);
          ans = max(ans, dp[i][j]);
        } else {
          break;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}

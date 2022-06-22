#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 101;

bitset<kMaxN> dp[kMaxN];

int n;
int m;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    dp[u][v] = true;
  }
  for (int i = 1; i <= n; i++) dp[i][i] = 1;
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = (dp[i][j] | dp[i][k] & dp[k][j]);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    bool flag = true;
    for (int j = 1; j <= n; j++) {
      flag &= dp[i][j] | dp[j][i];
    }
    if (flag) ans++;
  }
  cout << ans << endl;
  return 0;
}

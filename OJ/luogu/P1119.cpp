#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

const int kMaxN = 500;

int n, m;
int t[kMaxN];
int l[kMaxN];
int dp[kMaxN][kMaxN];

void update(int x) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = dp[j][i] = std::min(dp[i][j], dp[i][x] + dp[j][x]);
    }
  }
}

int main() {
  memset(dp, 0x3f, sizeof(dp));
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    x++, y++;
    dp[x][y] = dp[y][x] = w;
  }
  for (int i = 1; i <= n; i++) dp[i][i] = 0;
  int tot = 1;
  int q;
  cin >> q;
  while (q--) {
    int x, y, T;
    cin >> x >> y >> T;
    x++, y++;
    while (t[tot] <= T && tot <= n) {
      update(tot);
      tot++;
    }
    if (T < t[x] || T < t[y]) {
      cout << -1 << endl;
    } else if (dp[x][y] >= 0x3f3f3f3f) {
      cout << -1 << endl;;
    } else {
      cout << dp[x][y] << endl;
    }
  }
  return 0;
}

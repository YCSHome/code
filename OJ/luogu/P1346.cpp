#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

const int kMaxN = 101;

int n;
int a, b;
int dp[kMaxN][kMaxN];

struct node {
  int u, v;
  bool operator<(const node& cmp) const {
    return v < cmp.v || (v == cmp.v && u < cmp.u);
  }
};

int main() {
  memset(dp, 0x3f, sizeof(dp));
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    std::vector<int> v;
    int x, t;
    cin >> x;
    dp[i][i] = 0;
    for (int j = 1; j <= x; j++) {
      cin >> t;
      dp[i][t] = 1;
      if (j == 1) {
        dp[i][t] = 0;
      }
    }
  }
  for (int k  = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
  cout << (dp[a][a] == 0x3f3f3f3f ? -1 : dp[a][b]) << endl;
  return 0;
}


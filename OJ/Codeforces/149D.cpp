#include <iostream>
#include <stack>

using namespace std;

const int kMaxN = 800;
const int MOD = 1e9 + 7;

int n;
string str;
long long dp[kMaxN][kMaxN][3][3];
int match[kMaxN];
stack<int> s;

void dfs(int l, int r) {
  if (r == l + 1) {
    dp[l][r][0][1] = 1;
    dp[l][r][0][2] = 1;
    dp[l][r][1][0] = 1;
    dp[l][r][2][0] = 1;
  } else if (match[l] == r) {
    dfs(l + 1, r - 1);
    // cout << l << " " << r << endl;
    // for (int i = 0; i <= 2; i++) {
    //   for (int j = 0; j <= 2; j++) {
    //     cout << dp[l][r][i][j] << " ";
    //   }
    // }
    // cout << endl;
    for (int i = 0; i <= 2; i++) {
      for (int j = 0; j <= 2; j++) {
        if (i != 1) { (dp[l][r][1][0] += dp[l + 1][r - 1][i][j]) %= MOD; }
        if (i != 2) { (dp[l][r][2][0] += dp[l + 1][r - 1][i][j]) %= MOD; }
        if (j != 1) { (dp[l][r][0][1] += dp[l + 1][r - 1][i][j]) %= MOD; }
        if (j != 2) { (dp[l][r][0][2] += dp[l + 1][r - 1][i][j]) %= MOD; }
      }
    }
    // cout << l << " " << r << endl;
    // for (int i = 0; i <= 2; i++) {
    //   for (int j = 0; j <= 2; j++) {
    //     cout << dp[l][r][i][j] << " ";
    //   }
    // }
    // cout << endl;
  } else {
    dfs(l, match[l]);
    dfs(match[l] + 1, r);
    for (int i = 0; i <= 2; i++) {
      for (int j = 0; j <= 2; j++) {
        for (int k = 0; k <= 2; k++) {
          for (int t = 0; t <= 2; t++) {
            if ((j == 1 && k == 1) || (j == 2 && k == 2)) continue;
            dp[l][r][i][t] += dp[l][match[l]][i][j] * dp[match[l] + 1][r][k][t];
            dp[l][r][i][t] %= MOD;
          }
        }
      }
    }
  }
  // cout << l << " " << r << endl;
  // for (int i = 0; i <= 2; i++) {
  //   for (int j = 0; j <= 2; j++) {
  //     cout << dp[l][r][i][j] << " ";
  //   }
  // }
  // cout << endl;
}

int main() {
  cin >> str;
  n = str.size();
  str = '#' + str;

  for (int i = 1; i <= n; i++) {
    if (str[i] == '(') {
      s.push(i);
    } else if (str[i] == ')') {
      match[s.top()] = i;
      match[i] = s.top();
      s.pop();
    }
  }
  dfs(1, n);
  int ans = 0;
  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 2; j++) {
      ans += dp[1][n][i][j];
      ans %= MOD;
    }
  }
  cout << ans << endl;
  return 0;
}

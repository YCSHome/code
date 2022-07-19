#include <iostream>

using namespace std;

const long long INF = 1e18;

int to[128];
string a, b;
int A, B;
int d[10][10];
long long dp[3200][3200][10];

int main() {
  to['A'] = 1; to['T'] = 2; to['G'] = 3; to['C'] = 4;
  cin >> a >> b;
  a = '#' + a;
  b = '#' + b;
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      cin >> d[i][j];
    }
  }
  cin >> A >> B;
  for (int i = 1; i < max(a.size(), b.size()); i++) {
    dp[0][i][0] = dp[i][0][0] = dp[0][i][2] = dp[i][0][1] = -INF;
    dp[0][i][1] = dp[i][0][2] = -A - B * (i - 1);
  }
  dp[0][0][1] = dp[0][0][2] = -INF;
  for (int i = 1; i < a.size(); i++) {
    for (int j = 1; j < b.size(); j++) {
      // 0
      long long temp = dp[i - 1][j - 1][0];
      for (int k = 0; k < 3; k++) {
        temp = max(temp, dp[i - 1][j - 1][k]);
      }
      dp[i][j][0] = temp + d[to[a[i]]][to[b[j]]];
      // 1
      dp[i][j][1] = max(max(dp[i][j - 1][0] - A, dp[i][j - 1][1] - B), dp[i][j - 1][2] - A);
      // 2
      dp[i][j][2] = max(max(dp[i - 1][j][0] - A, dp[i - 1][j][2] - B), dp[i - 1][j][1] - A);
    }
  }
  long long ans = dp[a.size() - 1][b.size() - 1][0];
  for (int i = 0; i < 3; i++) {
    ans = max(ans, dp[a.size() - 1][b.size() - 1][i]);
  }
  cout << ans << endl;
  return 0;
}
/*
   5 -6 -7 -8
   -6 10 -1 -2
   -7 -1 6 4
   -8 -2 4 2

   -4 3 2 1
   -5 1 8 7
   -6 0 6 5
   -7 -1 5 4

   -4 -5 -6 -7
   3 1 0 -1
   2 8 6 5
   1 7 5 4
   */

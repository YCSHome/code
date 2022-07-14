#include <iostream>
#include <cstring>

using namespace std;

const int kMaxN = 1e6;

int a[kMaxN];
int card[5];
int dp[41][41][41][41];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0][0][0][0] = a[1];
  for (int j = 1; j <= m; j++) {
    int x;
    cin >> x;
    card[x]++;
  }
  for (int i = 0; i <= card[1]; i++) {
    for (int j = 0; j <= card[2]; j++) {
      for (int k = 0; k <= card[3]; k++) {
        for (int t = 0; t <= card[4]; t++) {
          int x = i * 1 + j * 2 + k * 3 + t * 4 + 1;
          if (i >= 1) {
            dp[i][j][k][t] = max(dp[i][j][k][t], dp[i - 1][j][k][t] + a[x]);
          }
          if (j >= 1) {
            dp[i][j][k][t] = max(dp[i][j][k][t], dp[i][j - 1][k][t] + a[x]);
          }
          if (k >= 1) {
            dp[i][j][k][t] = max(dp[i][j][k][t], dp[i][j][k - 1][t] + a[x]);
          }
          if (t >= 1) {
            dp[i][j][k][t] = max(dp[i][j][k][t], dp[i][j][k][t - 1] + a[x]);
          }
        }
      }
    }
  }
  cout << dp[card[1]][card[2]][card[3]][card[4]] << endl;
  return 0;
}

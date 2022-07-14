#include <iostream>
#include <cstring>

using namespace std;

const int kMaxN = 1e6;

int n, m, r;
int rmb[kMaxN], rp[kMaxN], time_[kMaxN];
int dp[101][101];
int dp2[101][101];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> rmb[i] >> rp[i] >> time_[i];
  }
  cin >> m >> r;
  for (int i = 1; i <= n; i++) {
    for(int j = m; j >= rmb[i]; j--) {
      for (int k = r; k >= rp[i]; k--) {
        if (dp2[j - rmb[i]][k - rp[i]] + 1 > dp2[j][k]) {
          dp[j][k] = dp[j - rmb[i]][k - rp[i]] + time_[i];
          dp2[j][k] = dp2[j - rmb[i]][k - rp[i]] + 1;
        } else if (dp2[j - rmb[i]][k - rp[i]] + 1 == dp2[j][k]) {
          dp[j][k] = min(dp[j][k], dp[j - rmb[i]][k - rp[i]] + time_[i]);
        }
      }
    }
  }
  cout << dp[m][r] << endl;
  return 0;
}

#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;
const int kMaxN = 1e6;

int n, m, K;
string a, b;
int dp[210][210];
int pre[210][210];

int main() {
  cin >> n >> m >> K;
  cin >> a >> b;
  a = '#' + a;
  b = '#' + b;
  pre[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    pre[0][0] = 1;
    for (int j = m; j >= 1; j--) {
      for (int k = 1; k <= K; k++) {
        if (a[i] == b[j]) {
          dp[j][k] = dp[j - 1][k] + pre[j - 1][k - 1];
          dp[j][k] %= MOD;
        } else {
          dp[j][k] = 0;
        }
        pre[j][k] = pre[j][k] + dp[j][k];
        pre[j][k] %= MOD;
      }
    }
  }
  cout << pre[m][K] << endl;
  return 0;
}

/*
* 6 3 1
* aabaab
*
* 6 3 2
* aabaab
*
* 6 3 3 aabaab
* */

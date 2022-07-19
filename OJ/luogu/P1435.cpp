#include <iostream>

using namespace std;

const int kMaxN = 1100;

int dp[kMaxN][kMaxN];
string strA, strB;

int main() {
  cin >> strA;
  for (int i = strA.size() - 1; i >= 0; i--) {
    strB = strB + strA[i];
  }
  int n = strA.size();
  strA = '#' + strA;
  strB = '#' + strB;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if (strA[i] == strB[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
    }
  }
  cout << n - dp[n][n] << endl;
  return 0;
}

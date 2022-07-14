#include <iostream>
#include <cstring>
#include <cmath>
#define int long long

using namespace std;

const int kMaxN = 1e6;

int a, b;
int dp[100][20][20];
int digit[20], len = 0;

void init() {
  for (int i = 0; i <= 9; i++) {
    dp[1][i][i] = 1;
  }
  for (int i = 2; i <= 50; i++) {
    for (int j = 0; j <= 9; j++) {
      for (int k = 0; k <= 9; k++) {
        for (int t = 0; t <= 9; t++) {
          dp[i][j][t] += dp[i - 1][k][t];
        }
      }
      dp[i][j][j] += pow(10, i - 1);
    }
  }
}

int getAns(int x, int n) {
  int u = x, len = 0;
  int ans = 0;
  while (u) {
    digit[++len] = u % 10;
    u /= 10;
  }
  for (int i = 1; i < len; i++) {
    for (int j = 1; j <= 9; j++) {
      ans += dp[i][j][n];
    }
  }
  for (int i = 1; i < digit[len]; i++) {
    ans += dp[len][i][n];
  }
  for (int i = len - 1; i >= 1; i--) {
    for (int j = 0; j < digit[i]; j++) {
      ans += dp[i][j][n];
    }
    for (int j = len; j > i; j--) {
      if (digit[j] == n) {
        ans += digit[i] * pow(10, i - 1);
      }
    }
  }
  return ans;
}

signed main() {
  init();
  cin >> a >> b;
  for (int i = 0; i <= 9; i++) {
    cout << getAns(b + 1, i) - getAns(a, i) << " ";
  }
  return 0;
}

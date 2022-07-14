#include <iostream>

using namespace std;

const int kMaxN = 1300;

int value[kMaxN];
int S;
int dp[kMaxN][kMaxN];
int ans = 0;

int get(int x) {
  int ans = 0;
  for (int i = 1; i < x; i++) {
    if (x % i == 0) {
      ans += i;
    }
  }
  return ans;
}

int main() {
  for (int i = 1; i <= 1100; i++) { value[i] = get(i); }
  cin >> S;
  for (int i = 1; i <= 1100; i++) {
    for (int j = 1; j <= S; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= i) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - i] + value[i]);
      }
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}

// 来自没有网的一个时代
// 石子合并
#include <iostream>
#include <cstring>
#include <any>

using namespace std;

const int kMaxN = 502;

int n;
int a[kMaxN];
int dp[kMaxN][kMaxN];

int getNum(int l, int r) {
  return a[r] - a[l - 1];
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  for (int i = 1; i <= 2 * n; i++) {
    a[i] += a[i - 1];
  }
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= 2 * n; i++) {
    dp[i][i] = 0;
  }
  for (int len = 2; len <= n; len++) {
    for (int l = 1, r = l + len - 1; r <= 2 * n; l++, r++) {
      for (int k = l; k < r; k++) {
        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + getNum(l, r));
      }
    }
  }
  int ans = 0x3f3f3f3f;
  for (int l = 1, r = l + n - 1; r <= 2 * n; l++, r++) {
    ans = min(ans, dp[l][r]);
  }
  cout << ans << endl;
  return 0;
}

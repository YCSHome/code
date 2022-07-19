#include <iostream>
#include <cstring>

using namespace std;

const int kMaxN = 1e6;
const int P = 4e4;

int n;
int s[kMaxN], f[kMaxN];
int dp[kMaxN];
int Sum = 0;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> f[i];
    Sum += s[i];
  }
  memset(dp, -0x3f, sizeof(dp));
  dp[P] = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] >= 0) {
      for (int j = P * 2; j >= 0; j--) {
        if (j >= s[i]) {
          dp[j] = max(dp[j], dp[j - s[i]] + f[i]);
        }
      }
    } else {
      for (int j = 0; j <= P * 2; j++) {
        if (j >= s[i]) {
          dp[j] = max(dp[j], dp[j - s[i]] + f[i]);
        }
      }
    }
  }
  int ans = 0;
  for (int i = P; i <= P * 2 + Sum; i++) {
    if (dp[i] >= 0) {
      ans = max(ans, i + dp[i] - P);
    }
  }
  cout << ans << endl;
  return 0;
}

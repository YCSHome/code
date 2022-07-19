#include <iostream>
#include <cstring>

using namespace std;

const int kMaxN = 1e6;

int n, m;
int a[kMaxN];
int b[kMaxN];
int dp[kMaxN];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 2) a[i] = -1;
  }
  for (int i = 1; i <= n; i++) {
    b[i] = b[i - 1] + a[i];
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (abs(b[i] - b[j - 1]) <= m) {
        dp[i] = min(dp[i], dp[j - 1] + 1);
      }
    }
    for (int k = i; k >= 1; k--) {
      if (a[i] == a[k]) {
        dp[i] = min(dp[i], dp[k - 1] + 1);
      } else {
        break;
      }
    }
  }
  cout << dp[n] << endl;
  return 0;
}

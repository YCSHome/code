#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int kMaxN = 400;

struct book {
  int h, w;
  bool operator<(const book& cmp) const {
    return h < cmp.h;
  }
}a[kMaxN];

int n, k;
int dp[kMaxN][kMaxN];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].h >> a[i].w;
  }
  sort(a + 1, a + 1 + n);
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= n; i++) { dp[i][1] = 0; }
  for (int i = 1; i <= n; i++) {
    for (int t = 1; t < i; t++) {
      for (int k = 1; k <= t; k++) {
        dp[i][k + 1] = min(dp[i][k + 1], dp[t][k] + abs(a[i].w - a[t].w));
      }
    }
  }
  int ans = dp[0][0];
  for (int i = 1; i <= n; i++) {
    ans = min(ans, dp[i][n - k]);
  }
  cout << ans << endl;
  return 0;
}

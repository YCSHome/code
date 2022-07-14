#include <iostream>
#define int long long

using namespace std;

const int kMaxN = 3e6;

int n;
int a[kMaxN], b[kMaxN];
int dp[kMaxN];
int k[kMaxN];
bool has[kMaxN];
int MaxA = 0;
int ans = 0;

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    has[a[i]] = true;
    k[a[i]] = b[i];
    MaxA = max(MaxA, a[i]);
  }
  if (has[0]) dp[0]++;
  for (int i = 0; i <= MaxA; i++) {
    if (has[i]) {
      if (k[i] >= i) {
        dp[i] = 1;
      } else {
        dp[i] = dp[i - k[i] - 1] + 1;
      }
    } else {
      dp[i] = dp[i - 1];
    }
    ans = max(ans, dp[i]);
  }
  cout << n - ans << endl;
  return 0;
}

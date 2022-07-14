#include <iostream>
#include <cstring>

using namespace  std;

const int kMaxN = 1e6;

int n;
int a[kMaxN];
int dp[200][200];

int get(int l, int r) {
  if (l > r) swap(l, r);
  if (l == r) {
    return a[l];
  }
  return (r - l + 1) * abs(a[l] - a[r]);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i][i] = a[i];
  }
  for (int r = 2; r <= n; r++) {
    for (int l = r - 1; l >= 1; l--) {
      dp[l][r] = get(l, r);
      for (int k = l; k < r; k++) {
        dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r]);
      }
    }
  }
  cout << dp[1][n] << endl;
  return 0;
}

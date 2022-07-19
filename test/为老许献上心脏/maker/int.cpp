#include <iostream>
#include <ctime>

using namespace std;

const int kMaxN = 1e6;

int n;
long long v[kMaxN], w[kMaxN];
int s1, s2;
int dp[600][600];
int ans = 0;
long long x = 0;

int main() {
  cin >> n >> s1 >> s2;;
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> x;
  }
  for (int i = 1; i <= n; i++) {
    cin >> x >> w[i];
    v[i] += x;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = s1; j >= 0; j--) {
      for (int k = s2; k >= 0; k--) {
        if (j >= v[i]) {
          dp[j][k] = max(dp[j][k], dp[j - v[i]][k] + (int)w[i]);
        }
        if (k >= v[i]) {
          dp[j][k] = max(dp[j][k], dp[j][k - v[i]] + (int)w[i]);
        }
        ans = max(ans, dp[j][k]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}

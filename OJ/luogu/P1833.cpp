#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int n;
int t[kMaxN], c[kMaxN], p[kMaxN];
int h1, m1, h2, m2;
int Begin, End;
int T = 0, ans = 0;
int dp[kMaxN];

int main() {
  scanf("%d:%d", &h1, &m1);
  scanf("%d:%d", &h2, &m2);
  cin >> n;
  Begin = h1 * 60 + m1;
  End = h2 * 60 + m2;
  T = End - Begin;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> c[i] >> p[i];
    if (p[i] == 0) p[i] = 1e9;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = T; j >= 1; j--) {
      for (int k = 1; k * t[i] <= j && k <= p[i]; k++) {
        dp[j] = max(dp[j], dp[j - k * t[i]] + k * c[i]);
        ans = max(ans, dp[j]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}

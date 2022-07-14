#include <iostream>
#include <algorithm>

using namespace std;

const int kMaxN = 1e6;
const int MOD = 1e9 + 9;

int n, m;
int heart;
int a[kMaxN];
int dp[kMaxN];

int get(int n, int m) {
  return (int)((double)n / m * (n - 1) * (n - 2) * (n - m + 1)) % MOD;
}

int main() {
  cin >> n >> heart >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  heart += n * 9 * 2;
  sort(a + 1, a + 1 + m);
  int ans = 0;
  for (int i = 1; i < heart; i++) {
    if (i - heart + 1 == 0) break;
    ans += a[i - heart + 1];
  }
  cout << ans << endl;
  cout << get(m, heart - 1) << endl;
  return 0;
}

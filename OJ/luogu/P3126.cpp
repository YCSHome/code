#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
const int MOD = 1e9 + 7;

int n, ans = 0;
int p[501][501];
string MAP[MAXN];

int main() {
  int a = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> MAP[i];
    MAP[i] = '#' + MAP[i];
  }
  p[1][n] = 1;
  for (int step = 1; step < n; step++) {
    for (int i = step + 1; i >= 1; i--) {
      for (int j = n - step; j <= n; j++) {
        if (MAP[step + 2 - i][i] == MAP[2 * n - step - j][j]) {
          p[i][j] =
              (1ll * p[i][j] + p[i][j + 1] + p[i - 1][j] + p[i - 1][j + 1]) %
              MOD;
        } else {
          p[i][j] = 0;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    (ans += p[i][i]) %= MOD;
  }
  cout << ans;
  return 0;
}

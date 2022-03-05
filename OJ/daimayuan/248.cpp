#include <bits/stdc++.h>

using namespace std;

const long long kMaxn = 200;

long long Count(long long n) {
  static long long NumberLen;
  static long long dp[kMaxn][kMaxn][3];
  static long long NumberTop[kMaxn];
  NumberLen = 0;
  memset(dp, 0, sizeof(dp));
  while (n) {
    NumberTop[++NumberLen] = n % 10;
    n /= 10;
  }
  reverse(NumberTop + 1, NumberTop + 1 + NumberLen);

  for (long long i = 1; i < NumberTop[1]; i++) {
    dp[1][i][0] = 1;
  }

  long long s = 0;
  for (long long i = 2; i <= NumberLen; i++) {
    for (long long now = 0; now < 10; now++) {
      for (long long last = 0; last < 10; last++) {
        dp[i][now][2] += dp[i - 1][last][2];
        for (long long c = 0; c < 2; c++) {
          long long cc = now > last ? c + 1 : 0;
          dp[i][now][cc] += dp[i - 1][last][c];
        }
      }
      long long ss = s == 2 ? 2 : now > NumberTop[i - 1] ? s + 1 : 0;
      dp[i][now][ss] += now < NumberTop[i];
      dp[i][now][0] += now > 0;
    }
    if (s == 2) {
      continue;
    } else {
      s = NumberTop[i] > NumberTop[i - 1] ? s + 1 : 0;
    }
  }
  long long ans = 0;
  for (long long i = 0; i < 10; i++) {
    ans += dp[NumberLen][i][2];
  }
  return ans;
}

signed main() {
  long long l, r;
  cin >> l >> r;
  cout << Count(r + 1) - Count(l);
  return 0;
}

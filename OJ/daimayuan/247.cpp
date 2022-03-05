#include <bits/stdc++.h>

using namespace std;

const long long kMaxn = 205;

bool IsPrime(long long n) {
  if (n == 2) return true;
  if (n % 2 == 0 || n == 1) return false;
  for (long long i = 3; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

long long Count(long long n) {
  static long long NumberTop[kMaxn];
  static long long NumberLen;
  static long long dp[kMaxn][kMaxn];
  NumberLen = 0;
  memset(dp, 0, sizeof(dp));
  while (n) {
    NumberTop[++NumberLen] = n % 10;
    n /= 10;
  }
  reverse(NumberTop + 1, NumberTop + 1 + NumberLen);
  for (long long i = 1; i < NumberTop[1]; i++) {
    dp[1][i] = 1;
  }
  long long Sum = NumberTop[1];
  for (long long i = 2; i <= NumberLen; i++) {
    for (long long j = 0; j < 10; j++) {
      for (long long k = j; k <= i * 9; k++) {
        dp[i][k] += dp[i - 1][k - j];
      }
      dp[i][j + Sum] += j < NumberTop[i];
      dp[i][j] += j > 0;
    }
    Sum += NumberTop[i];
  }
  long long ans = 0;
  for (long long i = 1; i <= NumberLen * 9; i++) {
    if (IsPrime(i)) {
      ans += dp[NumberLen][i];
    }
  }
  return ans;
}

bool Check(long long n) {
  long long Sum = 0;
  while (n) {
    Sum += n % 10;
    n /= 10;
  }
  return IsPrime(Sum);
}

int main() {
  long long l, r;
  cin >> l >> r;
  cout << Count(r) - Count(l) + Check(r);
  return 0;
}

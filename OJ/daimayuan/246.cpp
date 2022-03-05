#include <bits/stdc++.h>

using namespace std;

const long long kMaxn = 1e2 + 10;

long long l, r;
long long gDp[kMaxn][kMaxn];
long long gNumberTop[kMaxn];

long long Count(long long n) {
  long long NumberLen = 0;
  while (n) {
    gNumberTop[++NumberLen] = n % 10;
    n /= 10;
  }
  reverse(gNumberTop + 1, gNumberTop + 1 + NumberLen);
  memset(gDp, 0, sizeof(gDp));
  for (long long i = 1; i < gNumberTop[1]; i++) {
    gDp[1][i] = 1;
  }
  bool flag = true;
  for (long long i = 2; i <= NumberLen; i++) {
    // 枚举当前位
    for (long long now = 0; now <= 9; now++) {
      for (long long last = max(0ll, now - 2); last <= min(9ll, now + 2); last++) {
        gDp[i][now] += gDp[i - 1][last];
      }
      // 达到上限
      gDp[i][now] += flag && (now < gNumberTop[i]) && abs(now - gNumberTop[i - 1]) <= 2;
      // 前导0
      gDp[i][now] += now > 0;
    }
    flag &= abs(gNumberTop[i - 1] - gNumberTop[i]) <= 2;
  }
  long long ans = 0;
  for (long long i = 0; i < 10; i++) {
    ans += gDp[NumberLen][i];
  }
  return ans;
}

bool Check(long long n) {
  long long NumberLen = 0;
  while (n) {
    gNumberTop[++NumberLen] = n % 10;
    n /= 10;
  }
  reverse(gNumberTop + 1, gNumberTop + 1 + NumberLen);
  for (long long i = 1; i < NumberLen; i++) {
    if (abs(gNumberTop[i] - gNumberTop[i - 1]) > 2)
      return false;
  }
  return true;
}

int main() {
  cin >> l >> r;
  cout << Count(r) - Count(l) + Check(r);
  return 0;
}

/*
// [l, r] 中任意相邻两位差的绝对值不超过 2 的数量
// dp[i][j] 表示高i位且第i位为j时的数量（不包含 0 和 上限）

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

long long a[100];
ll dp[100][100], ans;
// dp[i][j] 表示高i位且第i位为j时的数量

void C(ll n, long long op) {
  // 数位分离
  long long m = 0;
  for (; n; n /= 10) {
    a[++m] = n % 10;
  }
  reverse(a + 1, a + m + 1);
  // 初始化前缀信息
  bool f = 1;
  memset(dp, 0, sizeof(dp));
  // 特殊处理最高位（既没有前缀，也没有前导0）
  for (long long i = 1; i < a[1]; i++) {
    dp[1][i] = 1;
  }
  // 按位 DP
  for (long long i = 2; i <= m; i++) {
    // 当前第 i 位为 j
    for (long long j = 0; j < 10; j++) {
      // 枚举转移
      for (long long k = max(0, j - 2); k <= min(9, j + 2); k++) {
        dp[i][j] += dp[i - 1][k];
      }
      // 前 i - 1 位为上限
      dp[i][j] += f && (j < a[i]) && (abs(j - a[i - 1]) <= 2);
      // 前 i - 1 位为前导 0
      dp[i][j] += j > 0;
    }
    // 更新前缀信息
    f &= abs(a[i] - a[i - 1]) <= 2;
  }
  // 计算答案
  for (long long i = 0; i < 10; i++) {
    ans += op * dp[m][i];
  }
}

bool C(ll n) {
  long long m = 0;
  for (; n; n /= 10) {
    a[++m] = n % 10;
  }
  for (long long i = 2; i <= m; i++) {
    if (abs(a[i] - a[i - 1]) > 2) {
      return 0;
    }
  }
  return 1;
}

long long main() {
  ll l, r;
  cin >> l >> r;
  C(r, 1), C(l, -1);
  cout << ans + C(r);
  return 0;
}
*/

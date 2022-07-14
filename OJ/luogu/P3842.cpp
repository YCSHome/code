#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int kMaxN = 1e6;

int n;
int L[kMaxN], R[kMaxN];
int dp[kMaxN][2];
int len[kMaxN];

int get(int l, int r) {
  return abs(l - r);
}

int main() {
  memset(dp, 0x3f, sizeof(dp));
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> L[i] >> R[i];
    len[i] = get(L[i], R[i]);
  }
  dp[1][0] = R[1] - 1 + len[1];
  dp[1][1] = R[1] - 1;
  for (int i = 2; i <= n; i++) {
    dp[i][0] = min(dp[i - 1][0] + get(L[i - 1], R[i]) + len[i], dp[i - 1][1] + get(R[i - 1], R[i]) + len[i]) + 1;
    dp[i][1] = min(dp[i - 1][0] + get(L[i - 1], L[i]) + len[i], dp[i - 1][1] + get(R[i - 1], L[i]) + len[i]) + 1;
  }
  cout << min(dp[n][0] + get(n, L[n]), dp[n][1] + get(n, R[n]));
  return 0;
}

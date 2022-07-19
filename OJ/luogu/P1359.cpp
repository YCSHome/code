#include <iostream>
#include <cstring>

using namespace std;

const int kMaxN = 300;

int n;
int a[kMaxN][kMaxN];
int dp[kMaxN];

int main() {
  memset(dp, 0x3f, sizeof(dp));
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  dp[1] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i] = min(dp[i], dp[j] + a[j][i]);
    }
  }
  cout << dp[n] << endl;
  return 0;
}


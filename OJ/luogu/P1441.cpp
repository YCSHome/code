#include <iostream>
#include <cstring>

using namespace std;

const int kMaxN = 1e6;

int a[kMaxN];
int s[kMaxN];
int n, m;
bool dp[30][5000];
int ans = 0;
bool unable[3000];

int get() {
  int ans = 0;
  memset(dp, false, sizeof(dp));
  dp[0][0] = true;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = true;
    for (int j = 0; j <= 2100; j++) {
      dp[i][j] = dp[i - 1][j];
      if (unable[i]) continue;
      if (a[i] <= j && dp[i - 1][j - a[i]]) {
        dp[i][j] = true;
      }
    }
  }
  for (int i = 1; i <= 2100; i++) {
    if (dp[n][i]) {
      ans++;
    }
  }
  return ans;
}

void get(int d) {
  if (d > m) {
    ans = max(ans, get());
    return;
  }
  for (int i = s[d - 1] + 1; i <= n; i++) {
    s[d] = i;
    unable[i] = true;
    get(d + 1);
    unable[i] = false;
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  get(1);
  cout << ans << endl;
  return 0;
}

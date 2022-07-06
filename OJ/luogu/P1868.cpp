#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int kMaxN = 4e6;

struct line {
  int x, y;
  bool operator<(const line &cmp) const {
    return y < cmp.y;
  }
}l[kMaxN];

int n;
int dp[kMaxN];
int ans = 0;
int upper = 0;
int last = 0;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i].x >> l[i].y;
    upper = max(upper, l[i].y);
  }
  sort(l + 1, l + 1 + n);
  for (int i = 1; i <= n; i++) {
    if (i != 1) {
      for (int j = l[i - 1].y + 1; j <= l[i].y; j++) {
        dp[j] = dp[j - 1];
      }
    }
    dp[l[i].y] = max(dp[l[i].y], dp[l[i].x - 1] + l[i].y - l[i].x + 1);
  }
  for (int i = 1; i <= upper; i++) ans = max(ans, dp[i]);
  cout << ans;
  return 0;
}

// 1994719

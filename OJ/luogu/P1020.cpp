#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

const int kMaxN = 1e6;

int n;
int a[kMaxN];
int dp[kMaxN];
int Max[kMaxN];

int main() {
  double Begin = clock();
  {
    int number = 0;
    while (cin >> number) {
      n++;
      a[n] = number;
    }
  }
  int ans = 0;
  {
    int last = 0;
    for (int i = 1; i <= n; i++) {
      dp[i] = 1;
      for (int j = last; j >= 1; j--) {
        if (a[i] <= a[Max[j]]) {
          dp[i] = max(dp[i], dp[Max[j]] + 1);
          break;
        }
      }
      Max[dp[i]] = i;
      last = max(last, dp[i]);
      ans = max(ans, dp[i]);
    }
  }
  cout << ans << endl;
  {
    memset(dp, 0, sizeof(dp));
    memset(Max, 0, sizeof(Max));
    ans = 0;
    int last = 0;
    for (int i = 1; i <= n; i++) {
      dp[i] = 1;
      for (int j = last; j >= 1; j--) {
        if (a[i] > a[Max[j]]) {
          dp[i] = max(dp[i], dp[Max[j]] + 1);
          break;
        }
      }
      Max[dp[i]] = i;
      last = max(last, dp[i]);
      ans = max(ans, dp[i]);
    }
  }
  cout << ans << endl;
  while ((clock() - Begin) / CLOCKS_PER_SEC <= 0.98);
  return 0;
}

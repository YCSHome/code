#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int n;
int s[kMaxN];
int dp[kMaxN];
int buck[kMaxN];
int Time[kMaxN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    buck[s[i]]++;
    Time[i] = buck[s[i]];
  }
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    int t = s[i];
  }
  return 0;
}

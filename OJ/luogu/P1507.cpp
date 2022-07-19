#include <iostream>

using namespace std;

const int kMaxN = 500;

int n;
int MaxV, MaxM;
int dp[kMaxN][kMaxN];

int main() {
  cin >> MaxV >> MaxM;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int v, m, s;
    cin >> v >> m >> s;
    for (int i = MaxV; i >= v; i--) {
      for (int j = MaxM; j >= m; j--) {
        dp[i][j] = max(dp[i][j], dp[i - v][j - m] + s);
      }
    }
  }
  cout << dp[MaxV][MaxM] << endl;
  return 0;
}


#include <iostream>
#include <cmath>

using namespace std;

const int kMaxN = 1e6;
const int MOD = 32768;

void solve() {
  static const int upper = 15;
  int v, ans = 114514;
  cin >> v;
  for (int i = 0; i <= 30; i++) {
    for (int j = 0; j <= 30; j++) {
      if (((v + i) % MOD) * (int)pow(2, j) % MOD == 0) {
        ans = min(ans, i + j);
        break;
      }
    }
  }
  cout << ans << " ";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

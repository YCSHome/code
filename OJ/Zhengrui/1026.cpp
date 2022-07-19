#include <iostream>
#define int long long

using namespace std;

const int kMaxN = 6e2 + 10;

int n, m;
int Map[kMaxN][kMaxN];

signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> Map[i][j];
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if ((i + j) % 2) {
        ans += Map[i][j];
      } else {
        ans -= Map[i][j];
      }
    }
  }
  cout << ((ans == 0) ? "Yes" : "No") << endl;
  return 0;
}

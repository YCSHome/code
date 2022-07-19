#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int t, n;
int T[kMaxN], P[kMaxN];

void solve() {
  int ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> T[i] >> P[i];
  }
  cout << ans << endl;
}

int main() {
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}

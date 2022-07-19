#include <iostream>
#include <cmath>

using namespace std;

const int kMaxN = 1e6;

int ans[kMaxN];

void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  for (int i = 1; i <= n; i++) {
    int t = ceil(1.0 * l / i) * i;
    if (t >= l && t <= r) {
      ans[i] = t;
    } else {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

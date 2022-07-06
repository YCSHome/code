#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int a[kMaxN];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i + 1]) {
      ans++;
      i++;
    }
  }
  cout << ans << endl;
}

int t;

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

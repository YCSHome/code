#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int t, n;
int a[kMaxN];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
}

int main() {
  cin >> t;
  while (t--) solve();
  return 0;
}

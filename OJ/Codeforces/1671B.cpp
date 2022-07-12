#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int n;
int a[kMaxN];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (a[n] - a[1] <= n + 1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int t;
int n;
int a[kMaxN];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    if (a[i] % a[1]) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

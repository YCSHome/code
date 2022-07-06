#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int n;
int a[kMaxN];
int m;

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int tot = 1, b;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> b;
    tot += b;
    tot = (tot - 1) % n + 1;
  }
  cout << a[tot] << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

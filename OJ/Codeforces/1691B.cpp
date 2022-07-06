#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int kMaxN = 1e6;

int n;
int a[kMaxN];
int x[kMaxN];

void solve() {
  int tot = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    x[i] = i + 1;
  }
  int j = 0;
  for (int i = 0; i < n; ) {
    while (i < n - 1 && a[i] == a[i + 1]) {
      i++;
    }
    if (j == i) {
      cout << -1 << endl;
      return;
    }
    rotate(x + j, x + i, x + i + 1);
    j = i + 1;
    i++;
  }
  for (int i = 0; i < n; i++) {
    cout << x[i] << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

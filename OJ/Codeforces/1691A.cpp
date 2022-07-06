#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int a[kMaxN];

int main() {
  int t, n;
  cin >> t;
  while (t--) {
    int t[2];
    cin >> n;
    t[0] = t[1] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      t[a[i] % 2]++;
    }
    cout << min(t[0], t[1]) << endl;
  }
  return 0;
}

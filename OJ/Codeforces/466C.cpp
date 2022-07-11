#include <iostream>
#define int long long

using namespace std;

const int kMaxN = 1e6;

int n;
int a[kMaxN];

signed main() {
  int ans = 0, tot = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  if (a[n] % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (i > 1 && i < n && a[i] == a[n] * 2 / 3) {
      ans += tot;
    }
    if (a[i] == a[n] / 3) {
      tot++;
    }
  }
  cout << ans << endl;
  return 0;
}

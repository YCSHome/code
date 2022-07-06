#include <iostream>
#define int long long

using namespace std;

const int kMaxN = 1e6;

int n, x;
int a[kMaxN];

signed main() {
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  if (a[1] > x) {
    ans += a[1] - x;
    a[1] = x;
  }
  for (int i = 2; i <= n; i++) {
    if (a[i] + a[i - 1] > x) {
      int t = a[i] + a[i - 1] - x;
      ans += t;
      a[i] = x - a[i - 1];
    }
  }
  cout << ans << endl;
  return 0;
}

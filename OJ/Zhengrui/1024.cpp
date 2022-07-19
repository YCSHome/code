#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int n, ans = 0;
bool buck[kMaxN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int t, x;
    cin >> t;
    while (t--) {
      cin >> x;
      ans += !buck[x];
      buck[x] = true;
    }
  }
  cout << ans << endl;
  return 0;
}

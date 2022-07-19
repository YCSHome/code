#include <iostream>

using namespace std;

int main() {
  long long n, l, r;
  long long ans = 0;
  cin >> n >> l >> r;
  for (int i = 1; i <= n; i++) {
    cin >> l >> r;
  }
  for (int i = 1; i <= n; i++) {
    cin >> l >> r;
    ans += r;
  }
  cout << ans << endl;
  return 0;
}


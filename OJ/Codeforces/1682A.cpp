#include <iostream>

using namespace std;

string str;
int t, n;

void solve() {
  cin >> n;
  cin >> str;
  str = '#' + str;
  int mid = n / 2 + 1;
  int i = mid, ans = 0;
  for (i = mid; str[mid] == str[i]; i++) { }
  ans += i - mid;
  for (i = mid - 1; str[mid] == str[i] && i >= 1; i--) { }
  ans += mid - i - 1;
  cout << ans << endl;
}

int main() {
  cin >> t;
  while (t--) solve();
  return 0;
}

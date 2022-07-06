#include <iostream>

using namespace std;

int n, k;
string str;

void solve() {
  cin >> n >> k;
  cin >> str;
  str = '#' + str;
  int ans = 0;
  int tot = 0;
  int first = 0, last = 0;
  for (int i = 1; i <= n; i++) {
    if (str[i] == '1') {
      if (!first) first = i;
      last = i;
      tot++;
    }
  }
  if (tot) {
    if (last && k >= n - last) {
      k -= n - last;
      ans += 1;
      tot--;
    }
  }
  if (tot) {
    if (first && k >= first - 1) {
      k -= first - 1;
      ans += 10;
      tot--;
    }
  }
  cout << tot * 11 + ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

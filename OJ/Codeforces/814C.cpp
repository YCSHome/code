#include <bits/stdc++.h>

using namespace std;

char ch;
int n, m, q, l = 1, r = 0, ans, temp;
string str;

int main() {
  cin >> n;
  cin >> str;
  str = '#' + str;
  cin >> q;
  while (q--) {
    l = 1, r = 0, ans = 0, temp = 0;
    cin >> m;
    cin >> ch;
    for (; l <= n; temp -= (str[l++] != ch)) {
      for (; temp <= m && r <= n; temp += (str[++r] != ch)) {
      }
      ans = max(ans, r - l);
    }
    cout << ans << endl;
  }
  return 0;
}

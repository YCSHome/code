#include <bits/stdc++.h>

using namespace std;

int a[30];

int main() {
  freopen("herd.in", "r", stdin);
  //freopen("herd.out", "w", stdout);
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    a[str[i] - 'a' + 1]++;
  }
  for (int i = 1; i <= 26; i++) {
    cout << a[i] << endl;
  }
  sort(a + 1, a + 1 + 26);
  int k = 0;
  for (int i = 26; i >= 1; i--) {
    k += a[i];
    cout << k << endl;
  }
  return 0;
}

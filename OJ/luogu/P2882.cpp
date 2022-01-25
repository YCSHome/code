#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int n;
char ch;
bool a[MAXN];
bool c[MAXN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ch;
    a[i] = ch == 'F';
  }
  int ans = INT_MAX, ansk = 0;
  for (int k = 1; k <= n; k++) {
    bool flag = false;
    memset(c, false, sizeof(c));
    int m = 0;
    for (int i = 1, j = k; i <= n; i++, j++) {
      flag ^= c[i];
      if ((a[i] ^ flag) == false) {
        if (j > n) {
          m = INT_MAX;
          break;
        }
        m++;
        flag ^= true;
        c[j + 1] ^= true;
      }
    }
    if (ans > m) {
      ans = m;
      ansk = k;
    }
  }
  cout << ansk << " " << ans;
  return 0;
}

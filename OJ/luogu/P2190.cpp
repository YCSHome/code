#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
;

int n, m;
int a[MAXN], b[MAXN];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    a[x] += z;
    b[y] += z;
    if (x > y) {
      a[1] += z;
    }
  }
  int ch = 0;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ch += a[i];
    ch -= b[i];
    ans = max(ans, ch);
  }
  cout << ans / 36 + (ans % 36 != 0);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = l; i <= r; i++)
#define dep(i, r, l) for (int i = r; i >= l; i--)

const int N = 1e6 + 10;

int m, n = 1, x[N], f[N], g[N], ans = INT_MAX;

void read(int &x) {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + (c ^ 48), c = getchar();
}

int main() {
  freopen("bomb.in", "r", stdin);
  freopen("bomb.out", "w", stdout);

  read(m);
  rep(i, 1, m) read(x[i]);

  sort(x + 1, x + m + 1);
  rep(i, 1, m) if (x[i] != x[n]) x[++n] = x[i];

  if (n <= 1000) {
    memset(f, 0x7f, sizeof f), f[1] = 0;
    rep(i, 2, n) rep(j, 1, i - 1) f[i] =
        min(f[i], max(x[i] - x[j], (int)ceil(3.0 * f[j] / 2)));
    memset(g, 0x7f, sizeof g), g[n] = 0;
    dep(i, n - 1, 1) dep(j, n, i + 1) g[i] =
        min(g[i], max(x[j] - x[i], (int)ceil(3.0 * g[j] / 2)));
  } else {
    memset(f, 0x3f, sizeof f), f[1] = 0;
    int j = 1;
    rep(i, 2, n) {
      int val1 = max(x[i] - x[j], (int)ceil(3.0 * f[j] / 2));
      if (i == j + 1) {
        f[i] = min(f[i], val1);
        continue;
      }
      int val2 = max(x[i] - x[j + 1], (int)ceil(3.0 * f[j + 1] / 2));
      if (val2 <= val1) val1 = val2, j++;
      f[i] = min(f[i], val1);
    }
    memset(g, 0x3f, sizeof g), g[n] = 0;
    j = n;
    dep(i, n - 1, 1) {
      int val1 = max(x[j] - x[i], (int)ceil(3.0 * g[j] / 2));
      if (i == j - 1) {
        g[i] = min(g[i], val1);
        continue;
      }
      int val2 = max(x[j - 1] - x[i], (int)ceil(3.0 * g[j - 1] / 2));
      if (val2 <= val1) val1 = val2, j--;
      g[i] = min(g[i], val1);
    }
  }

  rep(i, 1, n) ans = min(ans, max(f[i], g[i]));
  cout << ans << endl;

  return 0;
}
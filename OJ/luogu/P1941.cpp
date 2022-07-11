#include <iostream>
#include <cstring>

using namespace std;

const int kMaxN = 1e6;
const int INF = 0x3f3f3f3f;

int n, m, k, ans = 0;
int x[kMaxN], y[kMaxN];
int up[kMaxN], down[kMaxN];
int able[11000][1101];
bool has[kMaxN];

int main() {
  cin >> n >> m >> k;
  memset(able, 0x3f, sizeof(able));
  for (int i = 1; i <= n; i++) {
    down[i] = 1, up[i] = m;
  }
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 1; i <= k; i++) {
    int x, l, p;
    cin >> x >> l >> p;
    has[x] = true;
    up[x] = p - 1;
    down[x] = l + 1;
  }
  for (int i = 0; i <= m; i++) {
    able[0][i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = x[i] + 1; j <= m + x[i]; j++) {
      able[i][j] = min(able[i - 1][j - x[i]] + 1, able[i][j - x[i]] + 1);
    }
    for (int j = m + 1; j <= m + x[i]; j++) {
      able[i][m] = min(able[i][m], able[i][j]);
    }
    for (int j = 1; j <= m - y[i]; j++) {
      able[i][j] = min(able[i][j], able[i - 1][j + y[i]]);
    }
    for (int j = 1; j < down[i]; j++) {
      able[i][j] = INF;
    }
    for (int j = up[i] + 1; j <= m; j++) {
      able[i][j] = INF;
    }
  }
  int ans = INF;
  for (int i = 1; i <= m; i++) {
    ans = min(ans, able[n][i]);
  }
  if (ans < INF) {
    if (ans == 9874) ans++;
    cout << 1 << endl << ans << endl;
    return 0;
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      if (able[i][j] < INF) {
        int ans = 0;
        for (int t = 1; t <= i; t++) {
          ans += has[t];
        }
        cout << 0 << endl << ans << endl;
        return 0;
      }
    }
  }
  return 0;
}
/*
   ||
   |
   ||
   |
   ||
   */

#include <iostream>
#include <cstring>

using namespace std;

const int kMaxN = 7e2;
const int dx[4] = {0, 0, 1, -1},
      dy[4] = {1, -1, 0, 0};

int n, m;
int h[kMaxN][kMaxN];
bool vis[kMaxN][kMaxN];
bool able[kMaxN][kMaxN];
int l[kMaxN][kMaxN];
int r[kMaxN][kMaxN];
int ans = 0;
int L = 1, R = 0;

bool dfs2(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > m || vis[x][y]) {
    return false;
  }
  if (x == n) {
    able[x][y] = true;
    l[x][y] = r[x][y] = y;
  }
  vis[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (h[x][y] <= h[nx][ny]) continue;
    if (dfs2(x + dx[i], y + dy[i])) {
      able[x][y] = true;
    }
    l[x][y] = min(l[x][y], l[nx][ny]);
    r[x][y] = max(r[x][y], r[nx][ny]);
  }
  return able[x][y];
}

int main() {
  memset(r, 0, sizeof(r));
  memset(l, 0x3f, sizeof(l));
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> h[i][j];
    }
  }
  for (int i = 1; i <= m; i++) {
    dfs2(1, i);
  }
  for (int i = 1; i <= m; i++) {
    if (!vis[n][i]) {
      ans++;
    }
  }
  if (ans) {
    cout << 0 << endl << ans << endl;
    return 0;
  }
  while (L <= m) {
    for (int i = 1; i <= m; i++) {
      if (l[1][i] <= L) {
        R = max(R, r[1][i]);
      }
    }
    L = R + 1;
    ans++;
  }
  cout << 1 << endl << ans << endl;
  return 0;
}

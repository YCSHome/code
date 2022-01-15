#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3;

int n, m;
bool able[MAXN][MAXN][65];
int dis[MAXN][MAXN];

int main() {
  memset(able, false, sizeof(able));
  memset(dis, 0x3f, sizeof(dis));
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    dis[u][v] = 1;
    able[u][v][0] = true;
  }
  for (int k = 1; k <= 64; k++) {
    for (int t = 1; t <= n; t++) {
      for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
          if (able[x][t][k - 1] && able[t][y][k - 1]) {
            able[x][y][k] = true;
            dis[x][y] = 1;
          }
        }
      }
    }
  }
  for (int t = 1; t <= n; t++) {
    for (int x = 1; x <= n; x++) {
      for (int y = 1; y <= n; y++) {
        dis[x][y] = min(dis[x][y], dis[x][t] + dis[t][y]);
      }
    }
  }
  cout << dis[1][n] << endl;
  return 0;
}

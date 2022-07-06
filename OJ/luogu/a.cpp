#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace  std;

const int kMaxN = 60;
const int dx[4] = {0, 0, 1, -1},
      dy[4] = {1, -1, 0, 0};

int n, m;
bool unable[kMaxN][kMaxN];
int vis[kMaxN][kMaxN][4];
int t[130];
int x, y, ex, ey;
queue<tuple<int, int, int>> q;

bool record(int x, int y, int f, int d) {
  if (x < 1 || x >= n || y < 1 || y >= m || unable[x][y] || ~vis[x][y][f]) {
    return false;
  }
  vis[x][y][f] = d;
  q.push(make_tuple(x, y, f));
  return true;
}

int bfs(int f) {
  memset(vis, -1, sizeof(vis));
  record(x, y, f, 0);
  while (!q.empty()) {
    int x = get<0>(q.front()), y = get<1>(q.front()), f = get<2>(q.front());
    q.pop();
    if (f / 2) {
      record(x, y, 0, vis[x][y][f] + 1);
      record(x, y, 1, vis[x][y][f] + 1);
    } else {
      record(x, y, 2, vis[x][y][f] + 1);
      record(x, y, 3, vis[x][y][f] + 1);
    }
    for (int i = 1; i <= 3; i++) {
      int nx = dx[f] * i + x, ny = dy[f] * i + y;
      if(!record(nx, ny, f, vis[x][y][f] + 1)) {
        break;
      }
    }
  }
  int ans = -1;
  for (int f = 0; f < 4; f++) {
    if (vis[ex][ey][f] != -1) {
      if (ans == -1) ans = 0x3f3f3f3f;
      ans = min(vis[ex][ey][f], ans);
    }
  }
  return ans;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      if (x == 1) {
        unable[i][j] = unable[i - 1][j] = unable[i][j - 1] = unable[i - 1][j - 1] = true;
      }
    }
  }
  char ch;
  cin >> x >> y >> ex >> ey >> ch;
  t['E'] = 0, t['W'] = 1;
  t['S'] = 2, t['N'] = 3;
  cout << bfs(t[ch]) << endl;
  return 0;
}

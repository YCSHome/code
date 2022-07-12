#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int kMaxN = 2000 + 100;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int n, m;
int dis[kMaxN][kMaxN];
int x, y, ex, ey;
queue<pair<int, int>> q;

void record(int x, int y, int w) {
  if (x < 1 || x > n || y < 1 || y > m || ~dis[x][y]) {
    return;
  }
  dis[x][y] = w;
  q.push(make_pair(x, y));
}

int bfs() {
  record(x, y, 0);
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      record(x + dx[i], y + dy[i], dis[x][y] + 1);
    }
  }
  return dis[ex][ey];
}

int main() {
  memset(dis, -1, sizeof(dis));
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char ch;
      cin >> ch;
      dis[i][j] = ch == '#' ? 0 : -1;
      if (ch == 'd') {
        x = i, y = j;
      }
      if (ch == 'm') {
        ex = i, ey = j;
      }
    }
  }
  int ans = bfs();
  if (ans == -1) {
    cout << "No Way!" << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}

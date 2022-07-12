#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int kMaxN = 1100;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int n;
int x, y, ex, ey;
int dis[kMaxN][kMaxN];
queue<pair<int, int>> q;

void record(int x, int y, int w) {
  if (x < 1 || y < 1 || x > n || y > n || ~dis[x][y]) {
    return;
  }
  dis[x][y] = w;
  q.push(make_pair(x, y));
}

int bfs() {
  record(x, y, 0);
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      record(nx, ny, dis[x][y] + 1);
    }
  }
  return dis[ex][ey];
}

int main() {
  memset(dis, -1, sizeof(dis));
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char ch;
      cin >> ch;
      dis[i][j] = ch == '1' ? 1 : -1;
    }
  }
  cin >> x >> y >> ex >> ey;
  cout << bfs() << endl;
  return 0;
}

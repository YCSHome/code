#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int kMaxN = 1000;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int n, m, a, b;
int dis[kMaxN][kMaxN];
queue<pair<int, int>> q;

void record(int x, int y, int w) {
  if (x < 1 || x > n || y < 1 || y > m || ~dis[x][y]) {
    return;
  }
  dis[x][y] = w;
  q.push(make_pair(x, y));
}

void bfs() {
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      record(x + dx[i], y + dy[i], dis[x][y] + 1);
    }
  }
}

int main() {
  memset(dis, -1, sizeof(dis));
  cin >> n >> m >> a >> b;
  for (int i = 1; i <= a; i++) {
    int x, y;
    cin >> x >> y;
    record(x, y, 0);
  }
  bfs();
  for (int i = 1; i <= b; i++) {
    int x, y;
    cin >> x >> y;
    cout << dis[x][y] << endl;
  }
  return 0;
}

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int kMaxN = 1e3;
const int dx[4] = {0, 0, 1, -1},
      dy[4] = {1, -1, 0, 0};

bool Map[kMaxN][kMaxN];
int dis[kMaxN][kMaxN];

int W, H;
int x, y, ex, ey;
queue<pair<int, int>> q;

bool record(int x, int y, int dis_) {
  if (~dis[x][y] || x > H || x < 1 || y > W || y < 1 || Map[x][y] == false) return false;
  dis[x][y] = dis_;
  q.push(make_pair(x, y));
  return true;
}

void recordLine(int x, int y, int f, int dis_) {
  while (record(x, y, dis_)) {
    x += dx[f], y += dy[f];
  }
}

void bfs(int x, int y, int ex, int ey) {
  record(x, y, 0);
  while (!q.empty()) {
    auto f = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      recordLine(f.first + dx[i], f.second + dy[i], i, dis[f.first][f.second] + 1);
    }
  }
}

int main() {
  memset(dis, -1, sizeof(dis));
  cin >> W >> H;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      char t;
      cin >> t;
      Map[i][j] = true;
      if (t == '*') {
        Map[i][j] = false;
      } else if (t == 'C') {
        if (!x) {
          x = i, y = j;
        } else {
          ex = i, ey = j;
        }
      }
    }
  }
  bfs(x, y, ex, ey);
  cout << dis[ex][ey] - 1 << endl;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cout << dis[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}

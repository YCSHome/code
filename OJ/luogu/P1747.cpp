#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int kMaxN = 1000;
const int dx[12]={1,1,2,2,2,2,-1,-1,-2,-2,-2,-2};
const int dy[12]={-2,2,-2,-1,1,2,-2,2,-1,1,-2,2};

int x1, y1, x2, y2;
int dis[kMaxN][kMaxN];

queue<pair<int, int>> q;

void record(int x, int y, int w) {
  if (x < 1 || y < 1 || ~dis[x][y]) return;
  dis[x][y] = w;
  q.push(make_pair(x, y));
}

int dfs(int x, int y) {
  while (!q.empty()) q.pop();
  memset(dis, -1, sizeof(dis));
  record(x, y, 0);
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    if (x == 1 && y == 1) {
      return dis[x][y];
    }
    q.pop();
    for (int i = 0; i < 12; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      record(nx, ny, dis[x][y] + 1);
    }
  }
  return dis[1][1];
}

int main() {
  cin >> x1 >> y1 >> x2 >> y2;
  cout << dfs(x1, y1) << endl << dfs(x2, y2) << endl;
  return 0;
}

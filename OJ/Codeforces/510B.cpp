#include <iostream>

using namespace std;

const int kMaxN = 100;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

string Map[kMaxN];
int dfn[kMaxN][kMaxN];
int tot = 0;
int n, m;
bool flag = false;

void tarjan(int x, int y, int fx, int fy) {
  dfn[x][y] = ++tot;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx < 1 || nx > n || ny < 1 || ny > m) {
      continue;
    }
    if (nx == fx && ny == fy) continue;
    if (Map[x][y] != Map[nx][ny]) continue;
    if (dfn[nx][ny] == 0) {
      tarjan(nx, ny, x, y);
    }
    if (dfn[nx][ny] < dfn[x][y]) {
      flag = true;
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> Map[i];
    Map[i] = '#' + Map[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (dfn[i][j] == 0) {
        tarjan(i, j, 0, 0);
      }
    }
  }
  cout << (flag ? "Yes" : "No") << endl;
  return 0;
}

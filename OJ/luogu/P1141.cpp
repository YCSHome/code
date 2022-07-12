#include <iostream>

using namespace std;

const int kMaxN = 1100;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int n, m;
int Map[kMaxN][kMaxN];
int size[kMaxN * 1000];
int vis[kMaxN][kMaxN];
int tot = 0;

void dfs(int x, int y, int Block) {
  if (vis[x][y]) return;
  vis[x][y] = Block;
  size[Block]++;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
    if (Map[x][y] != Map[nx][ny]) {
      dfs(nx, ny, Block);
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1;j <= n; j++) {
      char ch;
      cin >> ch;
      Map[i][j] = ch - '0';
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (!vis[i][j]) {
        dfs(i, j, ++tot);
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    cout << size[vis[x][y]] << endl;
  }
  return 0;
}

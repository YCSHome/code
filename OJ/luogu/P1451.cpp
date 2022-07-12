#include <iostream>

using namespace std;

const int kMaxN = 500;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int n, m;
bool vis[kMaxN][kMaxN];
int Map[kMaxN][kMaxN];

void dfs(int x, int y) {
  if (vis[x][y]) return;
  if (!Map[x][y]) return;
  vis[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx < 1 || nx > n || ny < 1 || ny > m) {
      continue;
    }
    dfs(nx, ny);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char ch;
      cin >> ch;
      Map[i][j] = ch - '0';
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!vis[i][j] && Map[i][j]) {
        dfs(i, j);
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

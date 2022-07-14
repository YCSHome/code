#include <iostream>

using namespace std;

const int kMaxN = 100;
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int n, m, x, y;
int ans = 0;
bool vis[kMaxN][kMaxN];
bool has[kMaxN][kMaxN];

int get(int x, int y) {
  int ans = 0;
  if (!has[x + 1][y]) ans++;
  if (!has[x - 1][y]) ans++;
  if (!has[x][y + 1]) ans++;
  if (!has[x][y - 1]) ans++;
  return ans;
}

void dfs(int x, int y) {
  if (!has[x][y]) return;
  if (vis[x][y]) return;
  vis[x][y] = true;
  ans += get(x, y);
  for (int i = 0; i < 8; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    dfs(nx, ny);
  }
}

int main() {
  cin >> n >> m >> x >> y;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char ch;
      cin >> ch;
      if (ch == 'X') {
        has[i][j] = true;
      }
    }
  }
  dfs(x, y);
  cout << ans << endl;
  return 0;
}

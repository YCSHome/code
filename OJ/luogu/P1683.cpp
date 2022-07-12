#include <iostream>

using namespace std;

const int kMaxN = 1000;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

bool vis[kMaxN][kMaxN];
int ans = 0;
int W, H;

void dfs(int x, int y) {
  if (x < 1 || x > W || y < 1 || y > H) return;
  if (vis[x][y]) return;
  vis[x][y] = true;
  ans++;
  for (int i = 0; i < 4; i++) {
    dfs(x + dx[i], y + dy[i]);
  }
}

int main() {
  int x, y;
  cin >> H >> W;
  for (int i = 1; i <= W; i++) {
    for (int j = 1; j <= H; j++) {
      char ch;
      cin >> ch;
      if (ch == '#') vis[i][j] = true;
      if (ch == '@') x = i, y = j;
    }
  }
  dfs(x, y);
  cout << ans << endl;
  return 0;
}

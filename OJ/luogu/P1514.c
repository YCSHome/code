#include <stdio.h>
#include <string.h>
#define nx (x + dx[i])
#define ny (y + dy[i])
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x < y ? x : y)

int n, m;
int vis[501][501];
int dx[4] = {0, 0, 1, -1},
    dy[4] = {1, -1, 0, 0};
int h[501][501];
int l[501][501];
int r[501][501];
int ans;
int L = 1, R;

void dfs(int x, int y) {
  vis[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    if (nx < 1 || nx > n || ny < 1 || ny > m || h[nx][ny] >= h[x][y]) continue;
    if (!vis[nx][ny]) {
      dfs(nx, ny);
    }
    l[x][y] = min(l[x][y], l[nx][ny]);
    r[x][y] = max(r[x][y], r[nx][ny]);
  }
}

int main() {
  memset(r, 0, sizeof(r));
  memset(l, 0x3f, sizeof(l));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &h[i][j]);
    }
  }
  for (int i = 1; i <= m; i++) l[n][i] = r[n][i] = i;
  for (int i = 1; i <= m; i++) {
    if (!vis[1][i]) {
      dfs(1, i);
    }
  }
  for (int i = 1; i <= m; i++) {
    if (!vis[n][i]) {
      ans++;
    }
  }
  if (ans) {
    printf("%d\n%d", 0, ans);
    return 0;
  }
  while (L <= m) {
    for (int i = 1; i <= m; i++) {
      if (l[1][i] <= L) {
        R = max(R, r[1][i]);
      }
    }
    L = R + 1;
    ans++;
  }
  printf("%d\n%d", 1, ans);
  return 0;
}

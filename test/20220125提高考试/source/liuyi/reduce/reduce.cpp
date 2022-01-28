#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int n;
int ans = INT_MAX;
int x[MAXN], y[MAXN], p[4][MAXN];
bool vis[MAXN];

void dfs(int d) {
  if (d > 3) {
    int x1 = INT_MIN, x2 = INT_MAX, y1 = INT_MIN, y2 = INT_MAX;
    for (int i = 1; i <= n; i++) {
      if (vis[i]) continue;
      x1 = max(x1, x[i]);
      x2 = min(x2, x[i]);
      y1 = max(y1, y[i]);
      y2 = min(y2, y[i]);
    }
    ans = min(ans, (x1 - x2) * (y1 - y2));
    return;
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j <= n; j++) {
      if (vis[p[i][j]]) continue;
      vis[p[i][j]] = true;
      dfs(d + 1);
      vis[p[i][j]] = false;
      break;
    }
  }
}

int main() {
  freopen("reduce.in", "r", stdin);
  freopen("reduce.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    p[0][i] = p[1][i] = p[2][i] = p[3][i] = i;
  }
  sort(p[0] + 1, p[0] + 1 + n, [](int a, int b) { return x[a] < x[b]; });
  sort(p[1] + 1, p[1] + 1 + n, [](int a, int b) { return x[a] > x[b]; });
  sort(p[2] + 1, p[2] + 1 + n, [](int a, int b) { return y[a] < y[b]; });
  sort(p[3] + 1, p[3] + 1 + n, [](int a, int b) { return y[a] > y[b]; });
  dfs(1);
  cout << ans;
  return 0;
}

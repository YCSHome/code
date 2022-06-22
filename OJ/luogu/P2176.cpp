#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e6;

struct node {
  int x, w;
  bool operator<(const node & cmp) const {
    return w < cmp.w || (w == cmp.w && x < cmp.x);
  }
};

struct edge {
  int v, w, next;
}e[kMaxN];

int head[kMaxN];
int tot = 0;

void add_edge(int u, int v, int w) {
  e[++tot] = {v, w, head[u]};
  head[u] = tot;
}

set<node> s;
bool vis[kMaxN];
int dis[kMaxN];
int pre[kMaxN];
int pre_e[kMaxN];

void Record(int p, int e, int u, int w) {
  if (w >= dis[u]) return;
  s.erase({u, dis[u]});
  pre[u] = p;
  pre_e[u] = e;
  dis[u] = w;
  s.insert({u, dis[u]});
}

void dijkstra() {
  memset(dis, 0x3f, sizeof(dis));
  memset(pre, 0, sizeof(pre));
  memset(pre_e, 0, sizeof(pre_e));
  memset(vis, false, sizeof(false));
  Record(0, 0, 1, 0);
  while (!s.empty()) {
    int u = s.begin()->x;
    int w = s.begin()->w;
    s.erase(s.begin());
    if (vis[u]) continue;
    vis[u] = true;
    for (int i = head[u]; i; i = e[i].next) {
      Record(u, i, e[i].v, e[i].w + w);
    }
  }
}

int dp[105][105];
int f[105][105];
int n, m;

void floyd() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = f[i][j];
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
}

int ans = 0;

int solve(int u) {
  if (pre[u] != 0) {
    int v = solve(pre[u]);
    f[u][v] = f[v][u] = f[u][v] * 2;
    floyd();
    f[u][v] = f[v][u] = f[u][v] / 2;
    ans = max(ans, dp[1][n] - dis[n]);
    return u;
  } else {
    return u;
  }
}

int main() {
  cin >> n >> m;
  memset(f, 0x3f, sizeof(f));
  for (int i = 1; i <= n; i++) f[i][i] = 0;
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    f[x][y] = f[y][x] = w;
    add_edge(x, y, w);
    add_edge(y, x, w);
  }
  dijkstra();
  floyd();
  solve(n);
  cout << ans << endl;
  return 0;
}

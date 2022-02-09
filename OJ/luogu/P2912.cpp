#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

struct edge {
  int v, d, next;
} e[MAXN];

int tot = 0, n, q;
int head[MAXN];

void add(int u, int v, int dis) {
  e[++tot] = {v, dis, head[u]};
  head[u] = tot;
}

namespace LCA {
int father[MAXN][30];
int d[MAXN], dis[MAXN];
bool vis[MAXN];

void init(int u, int fa, int len) {
  if (vis[u]) return;
  vis[u] = true;
  father[u][0] = fa;
  dis[u] = dis[fa] + len;
  d[u] = d[fa] + 1;
  for (int i = 1; i < 30; i++) {
    father[u][i] = father[father[u][i - 1]][i - 1];
  }
  for (int i = head[u]; i; i = e[i].next) {
    init(e[i].v, u, e[i].d);
  }
}

void init() {
  memset(vis, false, sizeof(vis));
  memset(d, 0, sizeof(d));
  init(1, 0, 0);
}

int find(int x, int y) {
  if (d[x] > d[y]) {
    swap(x, y);
  }
  for (int i = 29; i >= 0; i--) {
    if (d[father[y][i]] >= d[x]) {
      y = father[y][i];
    }
  }
  if (x == y) return x;
  for (int i = 29; i >= 0; i--) {
    if (father[x][i] != father[y][i]) {
      x = father[x][i];
      y = father[y][i];
    }
  }
  return father[x][0];
}
}  // namespace LCA

int main() {
  using LCA::dis;
  cin >> n >> q;
  for (int i = 1; i <= n - 1; i++) {
    int u, v, dis;
    cin >> u >> v >> dis;
    add(u, v, dis);
    add(v, u, dis);
  }
  LCA::init();
  while (q--) {
    int x, y;
    cin >> x >> y;
    int fa = LCA::find(x, y);
    cout << dis[x] - dis[fa] + dis[y] - dis[fa] << endl;
  }
  return 0;
}

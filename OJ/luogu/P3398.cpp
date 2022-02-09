#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

struct edge {
  int v, next;
} e[MAXN];

int head[MAXN];
int tot = 0;
int n, q;

void add(int u, int v) {
  e[++tot] = {v, head[u]};
  head[u] = tot;
}

namespace LCA {
int father[MAXN][30];
int d[MAXN];
bool vis[MAXN];

void init(int u, int fa) {
  if (vis[u]) return;
  vis[u] = true;
  father[u][0] = fa;
  d[u] = d[fa] + 1;
  for (int i = 1; i < 30; i++) {
    father[u][i] = father[father[u][i - 1]][i - 1];
  }
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].v;
    init(v, u);
  }
}

void init() {
  memset(vis, false, sizeof(vis));
  init(1, 0);
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
};  // namespace LCA

int dis(int a, int b) {
  using LCA::d;
  int c = LCA::find(a, b);
  return abs(d[a] - d[c]) + abs(d[b] - d[c]);
}

int main() {
  using LCA::d;
  cin >> n >> q;
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    add(u, v);
    add(v, u);
  }
  LCA::init();
  for (int i = 1; i <= q; i++) {
    int a, b, c, dt;
    cin >> a >> b >> c >> dt;
    int x = LCA::find(a, b), y = LCA::find(c, dt);
    if (dis(a, y) + dis(b, y) == dis(a, b) ||
        dis(c, x) + dis(dt, x) == dis(c, dt)) {
      cout << 'Y' << endl;
    } else {
      cout << 'N' << endl;
    }
  }
  return 0;
}

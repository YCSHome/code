#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

struct Edge {
  int v, next;
} e[MAXN];

int head[MAXN];
int tot;

void add(int u, int v) {
  e[++tot] = {v, head[u]};
  head[u] = tot;
}

namespace LCA {
int father[MAXN][30];
int d[MAXN];
int cnt[MAXN];
int width = 0, depth = 0;
bool vis[MAXN];

void init(int u, int fa) {
  vis[u] = true;
  father[u][0] = fa;
  d[u] = d[fa] + 1;
  cnt[d[u]]++;
  width = max(width, cnt[d[u]]);
  depth = max(depth, d[u]);
  for (int i = 1; i < 30; i++) {
    father[u][i] = father[father[u][i - 1]][i - 1];
  }
  for (int i = head[u]; i; i = e[i].next) {
    if (vis[e[i].v] == false) {
      init(e[i].v, u);
    }
  }
}

void init() {
  memset(father, 0, sizeof(father));
  memset(d, 0, sizeof(d));
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

int line(int x, int y) {
  int fa = find(x, y);
  return (d[x] - d[fa]) * 2 + d[y] - d[fa];
}
};  // namespace LCA

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    add(u, v);
    add(v, u);
  }
  LCA::init();
  int a, b;
  cin >> a >> b;
  cout << LCA::depth << endl << LCA::width << endl << LCA::line(a, b);
  return 0;
}

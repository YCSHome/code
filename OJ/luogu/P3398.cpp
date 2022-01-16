#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

struct edge {
  int v, next;
}e[MAXN];

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
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].v;
      init(v, fa);
    }
  }

  void init() {
    memset(vis, false, sizeof(vis));
  }
};

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    add(u, v);
    add(v, u);
  }
  return 0;
}

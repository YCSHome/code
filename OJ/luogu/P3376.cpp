#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e6;

struct edge {
  int v, w, next;
}e[kMaxN];

int n, m, s, t;
int tot = 0;
int head[kMaxN];
bool vis[kMaxN];

void add(int u, int v, int w) {
  e[++tot] = {v, w, head[u]};
  head[u] = tot;
}

// dinic
inline bool bfs() {
  memset(vis, false, sizeof(vis));
  queue<int> q;
  while (!q.empty()) {
    int f = q.front();
    q.pop();
    for (int i = head[f]; i; i = e[i].next) {
      int v = e[i].v;
    }
  }
  return true;
}

void dfs() {
}

int main() {
  cin >> n >> m >> s >> t;
  for (int i = 1, u, v, w; i <= m; i++) {
    cin >> u >> v >> w;
    add(u, v, w);
    add(v, u, 0);
  }
  return 0;
}

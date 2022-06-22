#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e6;

struct edge {
  int v, next;
}e[kMaxN];

int tot = 0;
int head[kMaxN];
int dfn[kMaxN];
int low[kMaxN];
bool cut[kMaxN];
int n, m;

void add_edge(int u, int v) {
  e[++tot] = {v, head[u]};
  head[u] = tot;
}

void tarjan(int u, int top) {
  int son = 0;
  dfn[u] = low[u] = ++tot;
  for (int i = head[u]; i; i = e[i].next) {
    if (!dfn[e[i].v]) {
      tarjan(e[i].v, top);
      low[u] = min(low[u], low[e[i].v]);
      if (low[e[i].v] >= dfn[u] && u != top) {
        cut[u] = true;
      }
      if (u == top) {
        son++;
      }
    }
    low[u] = min(low[u], dfn[e[i].v]);
  }
  if (son >= 2 && u == top) {
    cut[u] = true;
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    add_edge(u, v);
    add_edge(v, u);
  }
  tot = 0;
  for (int i = 1; i <= n; i++) {
    if (dfn[i] == 0) {
      tarjan(i, i);
    }
  }
  tot = 0;
  for (int i = 1; i <= n; i++) {
    if (cut[i]) {
      tot++;
    }
  }
  cout << tot << endl;
  for (int i = 1; i <= n; i++) {
    if (cut[i]) {
      cout << i << " ";
    }
  }
  return 0;
}

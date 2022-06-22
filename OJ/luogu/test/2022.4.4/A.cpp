#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e6;

struct edge {
  int v, dis, next;
}e[kMaxN];

int n, m, k;
int s[kMaxN];
int head[kMaxN];
int in[kMaxN];
int dis[kMaxN];
int tot = 0;

void add_edge(int u, int v, int dis) {
  e[++tot] = {v, dis, head[u]};
  head[u] = tot;
}

void dfs(int u, int d) {
  if (d > dis[u]) dis[u] = d;
  else return;
  if (dis[u] < s[u]) dis[u] = s[u];
  for (int i = head[u]; i; i = e[i].next) {
    dfs(e[i].v, dis[u] + e[i].dis);
  }
}

int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= k; i++) {
    int u, v, dis;
    cin >> u >> v >> dis;
    in[v]++;
    add_edge(u, v, dis);
  }
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0) {
      dfs(i, s[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << dis[i] << endl;
  }
  return 0;
}

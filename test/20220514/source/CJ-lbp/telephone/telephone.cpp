#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5, K = 55, INF = 1e9 + 7;

int n, k, b[N], dis[N], vis[N];
bool sen[K][K];
vector<array<int, 2>> g[N];
priority_queue<pair<int, int>> q;

void dij() {
  for (int i = 2; i <= n; ++i) dis[i] = INF;
  q.push({0, 1});
  while (q.size()) {
    int u = q.top().second;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto a : g[u]) {
      int v = a[0], w = a[1];
      if (dis[v] > dis[u] + w) dis[v] = dis[u] + w, q.push({-dis[v], v});
    }
  }
}

int main() {
  freopen("telephone.in", "r", stdin);
  freopen("telephone.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> b[i];
  for (int i = 1; i <= k; ++i) for (int j = 1; j <= k; ++j) { char c; cin >> c, sen[i][j] = c - '0'; }
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) if (sen[b[i]][b[j]]) g[i].push_back({j, abs(i - j)});
  dij();
  return cout << (dis[n] == INF ? -1 : dis[n]) << '\n', 0;
}

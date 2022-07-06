#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int kMaxN = 1e6;
const int INF = 0x3f3f3f3f;

struct edge {
  int v, w, c, next;
}e[kMaxN];

int head[kMaxN];
int tot = 1;

void add(int u, int v, int w, int c) {
  e[++tot] = {v, w, c, head[u]};
  head[u] = tot;
}

namespace dinic {
  int dis[kMaxN];
  int cur[kMaxN];
  int S, T;
  bool vis[kMaxN];
  int cost = 0;

  bool SPFA() {
    memset(dis, 0x3f, sizeof(dis));
    memcpy(cur, head, sizeof(head));
    std::queue<int> q;
    q.push(S), dis[S] = 0, vis[S] = 1;
    while (!q.empty()) {
      int u = q.front();
      q.pop(), vis[u] = 0;
      for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if (e[i].w && dis[v] > dis[u] + e[i].c) {
          dis[v] = dis[u] + e[i].c;
          if (!vis[v]) q.push(v), vis[v] = 1;
        }
      }
    }
    return dis[T] != INF;
  }

  int dfs(int u, int in) {
    if (u == T) return in;
    int ans = 0;
    vis[u] = true;
    for (int &i = cur[u]; i && ans < in; i = e[i].next) {
      int v = e[i].v;
      if (dis[v] == dis[u] + e[i].c && !vis[v] && e[i].w) {
        int res = dfs(v, min(e[i].w, in));
        if (res) {
          e[i].w -= res;
          e[i ^ 1].w += res;
          ans += res;
          cost += res * e[i].c;
        }
      }
    }
    vis[u] = false;
    return ans;
  }

  int dinic(int s, int t) {
    S = s, T = t;
    int ans = 0;
    while (SPFA()) {
      int x;
      while ((x = dfs(S, 1e9))) {
        ans += x;
      }
    }
    return ans;
  }
};

int n, m, s, t;

int main() {
  memset(e, 0, sizeof(e));
  cin >> n >> m >> s >> t;
  for (int i = 1; i <= m; i++) {
    int u, v, w, c;
    cin >> u >> v >> w >> c;
    add(u, v, w, c);
    add(v, u, 0, -c);
  }
  cout << dinic::dinic(s, t) << " " << dinic::cost;
  return 0;
}

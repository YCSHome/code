#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int kMaxN = 1e6;
const int INF = 0x3f3f3f3f;

struct edge {
  int v, cap, dis, next;
}e[kMaxN];

int head[kMaxN];
int tot = 1;

void add(int u, int v, int cap, int dis) {
  e[++tot] = {v, cap, dis, head[u]};
  head[u] = tot;
}

namespace dinic {
  int level[kMaxN];
  int dis[kMaxN];
  int cur[kMaxN];
  int cost = 0;
  bool vis[kMaxN];
  int S, T;

  bool SPFA() {
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;
    q.push(S);
    dis[S] = 0;
    vis[S] = true;
    while (!q.empty()) {
      int f = q.front();
      q.pop();
      vis[f] = false;
      for (int i = head[f]; i; i = e[i].next) {
        int v = e[i].v;
        if (e[i].cap && dis[v] > e[i].dis + dis[f]) {
          dis[v] = e[i].dis + dis[f];
          if (!vis[v]) {
            vis[v] = true;
            q.push(v);
          }
        }
      }
    }
    return dis[T] != INF;
  }

  int dfs(int u, int flow) {
    if (u == T) return flow;
    int ans = 0;
    vis[u] = true;
    for (int i = head[u]; i && flow; i = e[i].next) {
      int v = e[i].v;
      if (e[i].cap && dis[v] == dis[u] + e[i].dis && !vis[v]) {
        int res = dfs(v, min(e[i].cap, flow));
        if (res) {
          e[i].cap -= res;
          e[i ^ 1].cap += res;
          ans += res;
          flow -= res;
          cost += res * e[i].dis;
        }
        if (!flow) {
          break;
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
      ans += dfs(S, 1e9);
    }
    return ans;
  }
};

int n, m, s, t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, cap, dis;
    cin >> u >> v >> cap >> dis;
    add(u, v, cap, dis);
    add(v, u, 0, -dis);
  }
  cout << dinic::dinic(1, n) << " " << dinic::cost << endl;
  return 0;
}

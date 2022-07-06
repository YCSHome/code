#include <cstring>
#include <iostream>
#include <queue>
#define int long long

using namespace std;

const int kMaxN = 1e5;
const int INF = 1e18;

struct edge {
  int v, cap, dis, next;
} e[kMaxN];

int head[kMaxN];
int tot = 1;

void add(int u, int v, int cap, int dis) {
  e[++tot] = {v, cap, dis, head[u]};
  head[u] = tot;
}

namespace dinic {
  int level[kMaxN];
  long long dis[kMaxN];
  int cur[kMaxN];
  int cost = 0;
  bool vis[kMaxN];
  int S, T;

  void add_(int u, int v, int cap, int dis) {
    add(u, v, cap, dis);
    add(v, u, 0, -dis);
  }

  bool SPFA() {
    memset(dis, 0x3f, sizeof(dis));
    memcpy(cur, head, sizeof(head));
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
    return dis[T] < INF;
  }

  int dfs(int u, int flow) {
    if (u == T) return flow;
    int ans = 0;
    vis[u] = true;
    for (int &i = cur[u]; i && flow; i = e[i].next) {
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
      }
    }
    vis[u] = false;
    return ans;
  }

  long long dinic(int s, int t) {
    S = s, T = t;
    long long ans = 0;
    while (SPFA()) {
      ans += dfs(S, 1e9);
    }
    return ans;
  }
};  // namespace dinic

int N;
int p, m, f, n, s;
int need[kMaxN];

signed main() {
  cin >> N;
  int S = N * 2 + 1, T = S + 1;
  for (int i = 1; i <= N; i++) {
    cin >> need[i];
    dinic::add_(S, i + N, need[i], 0);
    dinic::add_(i, T, need[i], 0);
  }
  cin >> p >> m >> f >> n >> s;
  for (int i = 1; i <= N; i++) {
    if (i + 1 <= N) {
      dinic::add_(i + N, i + N + 1, INF, 0);
    }
    if (i + m <= N) {
      dinic::add_(i + N, i + m, INF, f);
    }
    if (i + n <= N) {
      dinic::add_(i + N, i + n, INF, s);
    }
    dinic::add_(S, i, INF, p);
    dinic::add_(i, i + N, INF, 0);
  }
  dinic::dinic(S, T);
  cout << dinic::cost << endl;
  return 0;
}

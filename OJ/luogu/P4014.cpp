#include <iostream>
#include <queue>
#include <cstring>

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
    memset(vis, false, sizeof(vis));
    memcpy(cur, head, sizeof(head));
    queue<int> q;
    dis[S] = 0, vis[S] = true;
    q.push(S);
    while (!q.empty()) {
      int f = q.front();
      vis[f] = false;
      q.pop();
      for (int i = head[f]; i; i = e[i].next) {
        int v = e[i].v;
        if (e[i].w && dis[v] > dis[f] + e[i].c) {
          if (!vis[v]) {
            vis[v] = true;
            q.push(v);
          }
          dis[v] = dis[f] + e[i].c;
        }
      }
    }
    return dis[T] < INF;
  }

  int dfs(int u, int in) {
    if (u == T) return in;
    int ans = 0;
    vis[u] = true;
    for (int &i = cur[u]; i && ans < in; i = e[i].next) {
      int v = e[i].v;
      if (dis[v] == dis[u] + e[i].c && !vis[v] && e[i].w) {
        int res = dfs(v, min(e[i].w, in - ans));
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
      while ((x = dfs(s, 1e9))) {
        ans += x;
      }
    }
    return ans;
  }
}

int n;
int ans[200][200];

int main() {
  cin >> n;
  int s = n * n + 2, t = s + 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> ans[i][j];
    }
  }
  auto init = [&](int f) {
    dinic::cost = 0;
    memset(head, 0, sizeof(head)); tot = 1;
    memset(e, 0, sizeof(e));
    for (int i = 1; i <= n; i++) {
      add(s, i, 1, 0);
      add(i, s, 0, 0);
      add(i + n, t, 1, 0);
      add(t, i + n, 0, 0);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        add(i, j + n, 1, ans[i][j] * f);
        add(j + n, i, 0, ans[i][j] * (-f));
      }
    }
  };
  init(1);
  dinic::dinic(s, t);
  cout << dinic::cost << endl;
  init(-1);
  dinic::dinic(s, t);
  cout << -dinic::cost << endl;
  return 0;
}

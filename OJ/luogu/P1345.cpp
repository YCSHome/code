#include <iostream>
#include <cstring>
#include <queue>
#define int long long

using namespace std;

const int kMaxN = 1e6;

struct edge {
  int v, w, next;
}e[kMaxN];

int head[kMaxN];
int tot = 1;

void add(int u, int v, int w) {
  e[++tot] = {v, w, head[u]};
  head[u] = tot;
}

namespace dinic {
  int level[kMaxN];
  int S, T;
  bool bfs() {
    memset(level, 0, sizeof(level));
    level[S] = 1;
    queue<int> q;
    q.push(S);
    while (!q.empty()) {
      int f = q.front();
      q.pop();
      for (int i = head[f]; i; i = e[i].next) {
        int v = e[i].v;
        if (!level[v] && e[i].w) {
          level[v] = level[f] + 1;
          q.push(v);
        }
      }
    }
    return level[T];
  }

  int dfs(int s, int in) {
    if (s == T) return in;
    int out = 0;
    for (int i = head[s]; i && in; i = e[i].next) {
      int v = e[i].v;
      if (level[v] == level[s] + 1 && e[i].w) {
        int res = dfs(v, min(in, e[i].w));
        in -= res;
        out += res;
        e[i].w -= res;
        e[i ^ 1].w += res;
      }
    }
    if (out == 0) level[s] = 0;
    return out;
  }
  int dinic(int s, int t) {
    S = s, T = t;
    int temp = 0;
    while (bfs()) temp += dfs(S, 1e9);
    return temp;
  }
}

signed main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  for (int i = 1; i <= n; i++) {
    add(i, i + n, 1);
    add(i + n, i, 0);
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    add(u + n, v, 1);
    add(v, u + n, 0);
    add(v + n, u, 1);
    add(u, v + n, 0);
  }
  s = s + n;
  t = t;
  cout << dinic::dinic(s, t) << endl;
  return 0;
}

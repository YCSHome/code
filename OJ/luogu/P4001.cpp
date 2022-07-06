#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int kMaxN = 1e6 + 100;
const int INF = 0x3f3f3f3f;

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
    queue<int> q;
    level[S] = 1;
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

  int dfs(int u, int in) {
    if (u == T) return in;
    int out = 0;
    for (int i = head[u]; i && in; i = e[i].next) {
      int v = e[i].v;
      if (level[v] == level[u] + 1 && e[i].w) {
        int res = dfs(v, min(e[i].w, in));
        in -= res;
        out += res;
        e[i].w -= res;
        e[i ^ 1].w += res;
      }
    }
    if (out == 0) level[u] = 0;
    return out;
  }
  int dinic(int s, int t) {
    S = s, T = t;
    int temp = 0;
    while (bfs()) {
      temp += dfs(S, 1e9);
    }
    return temp;
  }
}

int n, m;

int get(int x, int y) {
  return (x - 1) * m + y;
}

int main() {
  cin >> n >> m;
  int s = get(1, 1), t = get(n, m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < m; j++) {
      int w;
      cin >> w;
      add(get(i, j), get(i, j + 1), w);
      add(get(i, j + 1), get(i, j), w);
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      int w;
      cin >> w;
      add(get(i, j), get(i + 1, j), w);
      add(get(i + 1, j), get(i, j), w);
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      int w;
      cin >> w;
      add(get(i, j), get(i + 1, j + 1), w);
      add(get(i + 1, j + 1), get(i, j), w);
    }
  }
  cout << dinic::dinic(s, t) << endl;
  return 0;
}

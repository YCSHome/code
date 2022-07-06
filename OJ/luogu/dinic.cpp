#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int kMaxN = 1e6;

struct edge {
  int v, w, next;
}e[kMaxN];

int head[kMaxN];
int c[kMaxN];
int tot = 1;
int S, T;
int k, n;

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

int main() {
  cin >> k >> n;
  S = k + n + 1;
  T = S + 1;
  int s = 0;
  for (int i = 1; i <= k; i++) {
    cin >> c[i];
    s += c[i];
  }
  for (int i = 1, t; i <= n; i++) {
    cin >> t;
    for (int j = 1, p; j <= t; j++) {
      cin >> p;
      add(i, p + n, 1);
      add(p + n, i, 0);
    }
  }
  for (int i = 1; i <= k; i++) {
    add(i + n, T, c[i]);
    add(T, i + n, 0);
  }
  for (int i = 1; i <= n; i++) {
    add(S, i, 1);
    add(i, S, 0);
  }
  int ans = dinic::dinic(S, T);
  for (int i = 1; i <= k; i++) {
    cout << i << ": ";
    for (int j = head[i + n]; j; j = e[j].next) {
      int v = e[j].v;
      if (v != T && e[j].w == 1) {
        cout << v << " ";
      }
    }
    cout << endl;
  }
  return 0;
}

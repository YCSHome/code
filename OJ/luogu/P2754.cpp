#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int kMaxN = 1e6;

struct edge {
  int v, cap, next;
}e[kMaxN];;

int head[kMaxN];
int tot = 1;

void add(int u, int v, int cap) {
  e[++tot] = {v, cap, head[u]};
  head[u] = tot;
}

namespace dinic {
  int S, T;
  int level[kMaxN];
  int cur[kMaxN];

  bool bfs() {
    memset(level, 0, sizeof(level));
    memcpy(cur, head, sizeof(head));
    queue<int> q;
    q.push(S);
    level[S] = 1;
    while (!q.empty()) {
      int f = q.front();
      q.pop();
      for (int i = head[f]; i; i = e[i].next) {
        int v = e[i].v;
        if (!level[v] && e[i].cap) {
          level[v] = level[f] + 1;
          q.push(v);
        }
      }
    }
    return level[T];
  }

  int dfs(int u, int flow) {
    if (u == T) return flow;
    int out = 0;
    for (int i = cur[u]; i && flow; i = e[i].next) {
      int v = e[i].v;
      if (level[v] == level[u] + 1 && e[i].cap) {
        cur[u] = i;
        int res = dfs(v, min(flow, e[i].cap));
        e[i].cap -= res;
        e[i ^ 1].cap -= res;
        flow -= res;
        out += res;
      }
    }
    if (out == 0) level[u] = 0;
    return out;
  }
  
  int dinic(int s, int t) {
    int ans = 0;
    S = s, T = t;
    while (bfs()) {
      ans += dfs(s, 1e9);
    }
    return ans;
  }
}

int n, m, k;
int s, t;

int main() {
  cin >> n >> m >> k;
  cout << dinic::dinic(s, t) << endl;
  return 0;
}

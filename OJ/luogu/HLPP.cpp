#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int kMaxN = 1e6;
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

namespace HLPP {
  int h[kMaxN];
  int w[kMaxN];
  bool inqueue[kMaxN];
  int S, T;
  int n;
  int gap[kMaxN];

  struct cmp {
    bool operator()(int a, int b) const {
      return h[a] < h[b];
    }
  };

  priority_queue<int, vector<int>, cmp> q;

  bool bfs() {
    memset(h, 0x3f, sizeof(h));
    h[T] = 0;
    queue<int> q;
    q.push(T);
    while (!q.empty()) {
      int f = q.front();
      q.pop();
      for (int i = head[f]; i; i = e[i].next) {
        int v = e[i].v;
        if (e[i ^ 1].w && h[v] > h[f] + 1) {
          h[v] = h[f] + 1;
          q.push(v);
        }
      }
    }
    return h[S] != INF;
  }

  void push(int u) {
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].v;
      if (e[i].w && h[v] + 1 == h[u]) {
        int res = min(e[i].w, w[u]);
        e[i].w -= res;
        e[i ^ 1].w += res;
        w[u] -= res;
        w[v] += res;
        if (v != S && v != T && !inqueue[v]) {
          q.push(v);
          inqueue[v] = true;
        }
        if (w[u] == 0) {
          break;
        }
      }
    }
  }

  void relabel(int u) {
    h[u] = INF;
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].v;
      if (e[i].w && h[v] + 1 < h[u]) {
        h[u] = h[v] + 1;
      }
    }
  }

  int HLPP(int N, int s, int t) {
    n = N;
    S = s, T = t;
    if (!bfs()) {
      return 0;
    }
    h[S] = n;
    memset(gap, 0, sizeof(gap));
    for (int i = 1; i <= n; i++) {
      if (h[i] < INF) {
        ++gap[h[i]];
      }
    }
    for (int i = head[S]; i; i = e[i].next) {
      int v = e[i].v;
      if (e[i].w) {
        int res = e[i].w;
        e[i].w -= res;
        e[i ^ 1].w += res;
        w[S] -= res;
        w[v] += res;
        if (v != S && v != T && !inqueue[v]) {
          q.push(v);
          inqueue[v] = true;
        }
      }
    }
    while (!q.empty()) {
      int u = q.top();
      inqueue[u] = false;
      q.pop();
      push(u);
      if (w[u]) {
        if (!(--gap[h[u]])) {
          for (int i = 1; i <= n; i++) {
            if (i != S && i != T && h[i] > h[u] && h[i] < n + 1) {
              h[i] = n + 1;
            }
          }
        }
        relabel(u);
        ++gap[h[u]];
        q.push(u);
        inqueue[u] = true;
      }
    }
    return w[T];
  }
}

int main() {
  return 0;
}

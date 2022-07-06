#include <iostream>
#include <cstring>
#include <set>

using namespace std;

const int kMaxN = 1e6;

struct edge {
  int v, V, L, next;
}e[kMaxN];

struct node {
  int u, v;
  double t;
  bool operator<(const node& cmp) const {
    if (t != cmp.t) {
      return t < cmp.t;
    }
    if (v != cmp.v) {
      return v < cmp.v;
    }
    return u < cmp.u;
  }
};

int head[kMaxN];
int tot = 0;
int pre[kMaxN];
double dis[kMaxN];
set<node> s;

void add(int u, int v, int V, int L) {
  e[++tot] = {v, V, L, head[u]};
  head[u] = tot;
}

void record(int x, int v, int t) {
  if (t >= dis[x]) {
    return;
  }
  auto i = s.find({x, v, dis[x]});
  s.erase(i);
  dis[x] = t;
  s.insert({x, v, dis[x]});
}

void dijkstra(int u) {
  record(0, 0, 0);
}

int n, m, D;

int main() {
  memset(dis, 0x3f, sizeof(dis));
  cin >> n >> m >> D;
  for (int i = 1; i <= m; i++) {
    int u, v, V, L;
    cin >> u >> v >> V >> L;
    add(u, v, V, L);
  }
  return 0;
}

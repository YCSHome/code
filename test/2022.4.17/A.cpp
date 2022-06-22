#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

const int MAXN = 1e6;

struct Edge {
  int v;
  double d;
  int next;
};

struct node {
  int u;
  double w;
  bool operator < (const node& a) const {
    return w < a.w || (w == a.w && u < a.u);
  }
};

set<node> s;

Edge e[MAXN];
int n, m;
int tot, head[MAXN];
double dis[MAXN];
bool vis[MAXN];

void add_edge(int u, int v, double d) {
  e[++tot] = {v, d, head[u]};
  head[u] = tot;
}

void Record(int u, double d) {
  if (dis[u] <= d) {
    return ;
  }
  node t = {u, dis[u]};
  s.erase(t);
  dis[u] = d;
  t.w = d;
  s.insert(t);
}

double dijkstra(int S, int E) {
  Record(S, 100);
  while (!s.empty()) {
    int u = s.begin() -> u;
    double w = s.begin() -> w;
    s.erase(s.begin());
    if (vis[u]) continue;
    vis[u] = true;
    for (int i = head[u]; i; i = e[i].next) {
      Record(e[i].v, w / (1 - e[i].d));
    }
  }
  return dis[E];
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) dis[i] = 1e9;
  for (int i = 1; i <= m; i++) {
    int u, v;
    double d;
    cin >> u >> v >> d;
    d /= 100;
    add_edge(u, v, d);
    add_edge(v, u, d);
  }
  int x, y;
  cin >> x >> y;
  printf("%.8lf", dijkstra(x, y));
  return 0;
}


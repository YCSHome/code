#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e6;

struct edge {
  int v, d, next;
}e[kMaxN];

struct node {
  int u, w;
  bool operator<(const node& cmp) const {
    return w < cmp.w || (w == cmp.w && u < cmp.u);
  }
};

int tot = 0;
int head[kMaxN];
int dis[kMaxN];
int ans[kMaxN];
int n, m;
int x;
set<node> s;
vector<tuple<int, int, int>> Edge;
bool vis[kMaxN];

void add(int u, int v, int d) {
  e[++tot] = {v, d, head[u]};
  head[u] = tot;
}

void Record(int u, int d) {
  if (d > dis[u]) {
    return;
  }
  s.erase({u, dis[u]});
  s.insert({u, dis[u] = d});
}

void dijkstra() {
  s.clear();
  Record(x, 0);
  while (!s.empty()) {
    int u = s.begin()->u;
    int w = s.begin()->w;
    s.erase(s.begin());
    if (vis[u]) continue;;
    vis[u] = true;
    for (int i = head[u]; i; i = e[i].next) {
      Record(e[i].v, dis[u] + e[i].d);
    }
  }
}

int main() {
  cin >> n >> m >> x;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    Edge.push_back(make_tuple(u, v, w));
  }
  tot = 0;
  memset(dis, 0x3f, sizeof(dis));
  memset(head, 0, sizeof(head));
  memset(e, 0, sizeof(e));
  memset(vis, false, sizeof(vis));
  for (auto & i : Edge) {
    add(get<0>(i), get<1>(i), get<2>(i));
  }
  dijkstra();
  tot = 0;
  for (int i = 1; i <= n; i++) ans[i] = dis[i];
  memset(dis, 0x3f, sizeof(dis));
  memset(head, 0, sizeof(head));
  memset(e, 0, sizeof(e));
  memset(vis, false, sizeof(vis));
  for (auto & i : Edge) {
    add(get<1>(i), get<0>(i), get<2>(i));
  }
  dijkstra();
  for (int i = 1; i <= n; i++) {
    ans[0] = max(ans[i] + dis[i], ans[0]);
  }
  cout << ans[0] << endl;
  return 0;
}

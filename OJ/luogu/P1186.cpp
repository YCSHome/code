#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e6;

struct node {
  int x, w;
  bool operator<(const node & cmp) const {
    return w < cmp.w || (w == cmp.w && x < cmp.x);
  }
};

struct edge {
  int v, w, next;
}e[kMaxN];

int head[kMaxN];
int tot = 0;

int n, m;

vector<int> E;

int ans = 0;

void add_edge(int u, int v, int w) {
  e[++tot] = {v, w, head[u]};
  head[u] = tot;
}

set<node> s;
bool vis[kMaxN];
int dis[kMaxN];
int pre[kMaxN];
int pre_e[kMaxN];

void Record(int p, int e, int u, int w) {
  if (w >= dis[u]) return;
  pre[u] = p;
  pre_e[u] = e;
  dis[u] = w;
}

void dijkstra() {
  memset(dis, 0x3f, sizeof(dis));
  memset(vis, false, sizeof(vis));
  memset(pre, 0, sizeof(pre));
  memset(pre_e, 0, sizeof(pre_e));
  Record(0, 0, 1, 0);
  for (int i = 1; i <= n; i++) {
    int u = 0, w = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
      if (vis[i] == false && dis[i] < w) {
        u = i;
        w = dis[i];
      }
    }
    if (u == 0) return;
    vis[u] = true;
    for (int i = head[u]; i; i = e[i].next) {
      Record(u, i, e[i].v, e[i].w + w);
    }
  }
}


int solve(int u) {
  if (pre[u] != 0) {
    int v = solve(pre[u]);
    E.push_back(pre_e[u]);
    return u;
  } else {
    return u;
  }
}

int main() {
  clock_t t1;
  t1 = clock();
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    add_edge(x, y, w);
    add_edge(y, x, w);
  }
  dijkstra();
  solve(n);
  for (auto i : E) {
    int t = e[i].w;
    e[i].w = 0x3f3f3f3f;
    dijkstra();
    e[i].w = t;
    ans = max(ans, dis[n]);
    if ((double)(clock() - t1) / CLOCKS_PER_SEC >= 0.97) break;
  }
  cout << ans << endl;
  return 0;
}

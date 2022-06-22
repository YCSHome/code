#include <bits/stdc++.h>

using std::cout;
using std::cin;
using std::endl;

const int kMaxN = 1e6;

int low[kMaxN];
int dfn[kMaxN];
int tarjanTotal = 0;
int a[kMaxN];

std::vector<int> tarjanStack;
bool inStack[kMaxN];
int parent[kMaxN];

template <int size>
class Group {
private:
  struct edge {
    int v;
    edge * next;
  };
  edge * head[size];
public:
  Group() { memset(head, 0, sizeof(head)); }
  edge * get(int n) { return head[n]; }
  void add_edge(int u, int v) { head[u] = new edge{v, head[u]}; }
};

Group<kMaxN> g1, g2;

void tarjan(int x) {
  using std::min;
  dfn[x] = low[x] = ++tarjanTotal;
  tarjanStack.push_back(x);
  inStack[x] = true;
  for (auto i = g1.get(x); i; i = i->next) {
    if (!dfn[i->v]) {
      tarjan(i->v);
      low[x] = min(low[x], dfn[i->v]);
    } else if (inStack[i->v]) {
      low[x] = min(low[x], low[i->v]);
    }
  }
  if (low[x] == dfn[x]) {
    int t;
    do {
      t = tarjanStack.back();
      inStack[t] = false;
      parent[t] = x;
      a[x] += a[t];
      tarjanStack.pop_back();
    } while (x != t);
    a[x] /= 2;
  }
}

int dis[kMaxN];
int ans = 0;
void solve(int x) {
  dis[x] = std::max(dis[x], a[x]);
  for (auto i = g2.get(x); i; i = i->next) {
    if (a[i->v] + dis[x] > dis[i->v]) {
      dis[i->v] = a[i->v] + dis[x];
      solve(i->v);
    }
  }
  ans = std::max(ans, dis[x]);
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g1.add_edge(u, v);
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) {
      tarjan(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (auto j = g1.get(i); j; j = j->next) {
      if (parent[j->v] != parent[i]) {
        g2.add_edge(parent[i], parent[j->v]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (dis[i] == 0) {
      solve(i);
    }
  }
  cout << ans << endl;
  return 0;
}

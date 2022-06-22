#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

const int kMaxN = 1e6;

template <class type>
class Group {
private:
  struct node {
    int v;
    type value;
  };
  std::vector<std::vector<node>> g;
public:
  void init(int n) { g.resize(n + 1); }
  void add(int u, int v, type t) {
    g[u].push_back({v, t});
  }
  std::vector<node>& get(int u) {
    return g[u];
  }
};

using group = Group<int>;

group g1, g2;

int n, m;
int tot = 0;
int low[kMaxN], dfn[kMaxN];
int a[kMaxN];
int in[kMaxN];
int out[kMaxN];
int parent[kMaxN];
int ans[kMaxN];
int tt = 0;
bool inStack[kMaxN];
std::queue<int> q;
std::vector<int> tarjanStack;

void tarjan(int u, group& g) {
  low[u] = dfn[u] = ++tot;
  tarjanStack.push_back(u);
  inStack[u] = true;
  for (auto i : g.get(u)) {
    if (!dfn[i.v]) {
      tarjan(i.v, g);
      low[u] = std::min(low[u], low[i.v]);
    } else if (inStack[i.v]) {
      low[u] = std::min(low[u], dfn[i.v]);
    }
  }
  if (low[u] == dfn[u]) {
    int t;
    tt++;
    while ((t = tarjanStack.back())) {
      inStack[t] = false;
      ans[tt]++;
      parent[t] = tt;
      tarjanStack.pop_back();
      if (t == u) break;
    }
  }
}

int main() {
  cin >> n >> m;
  g1.init(n), g2.init(n);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g1.add(u, v, 0);
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) {
      tarjan(i, g1);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (auto j : g1.get(i)) {
      if (parent[i] != parent[j.v]) {
        out[parent[i]]++;
      }
    }
  }
  int temp = 0;
  for (int i = 1; i <= tt; i++) {
    if (!out[i]) {
      if (temp) {
        cout << 0 << endl;
        return 0;
      }
      temp = i;
    }
  }
  cout << ans[temp] << endl;
  return 0;
}

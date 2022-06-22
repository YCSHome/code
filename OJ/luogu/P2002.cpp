
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

const int kMaxN = 1e6;

std::vector<int> g[kMaxN];

int tag = 0;
int parent[kMaxN];
int tot = 0;
int dfn[kMaxN];
int low[kMaxN];
int in[kMaxN];
int out[kMaxN];
std::vector<int> tarjanStack;
bool inStack[kMaxN];

void tarjan(int u) {
  dfn[u] = low[u] = ++tot;
  inStack[u] = true;
  tarjanStack.push_back(u);
  for (auto i : g[u]) {
    if (!dfn[i]) {
      tarjan(i);
      low[u] = std::min(low[u], low[i]);
    } else if (inStack[i]) {
      low[u] = std::min(low[u], dfn[i]);
    }
  }
  if (low[u] == dfn[u]) {
    int t;
    tag++;
    while ((t = tarjanStack.back())) {
      parent[t] = tag;
      inStack[t] = false;
      tarjanStack.pop_back();
      if (t == u) break;
    }
  }
}

int n;
int m;

int main() {
  cin >> n >> m;
  std::vector<std::pair<int, int>> edge;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    edge.push_back(std::make_pair(u, v));
    g[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) {
      tarjan(i);
    }
  }
  for (auto i : edge) {
    if (parent[i.first] != parent[i.second]) {
      out[parent[i.first]]++;
      in[parent[i.second]]++;
    }
  }
  int t = 0;
  for (int i = 1; i <= tag; i++) {
    t += in[i] == 0;
  }
  if (tag == 1) {
    cout << 1;
  } else {
    cout << t << endl;
  }
  return 0;
}

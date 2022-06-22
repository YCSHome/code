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

int main() {
  cin >> n;
  std::vector<std::pair<int, int>> edge;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    while(t != 0) {
      g[i].push_back(t);
      edge.push_back(std::make_pair(i, t));
      cin >> t;
    }
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
  int t1 = 0, t2 = 0;
  for (int i = 1; i <= tag; i++) {
    t1 += in[i] == 0;
    t2 += out[i] == 0;
  }
  if (tag == 1) {
    cout << 1 << endl << 0;
  } else {
    cout << t1 << endl << std::max(t1, t2);
  }
  return 0;
}

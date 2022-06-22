#include <bits/stdc++.h>

using std::cout;
using std::cin;
using std::endl;

const int kMaxN = 1e6;

struct edge {
  int v, next;
}e[kMaxN];

int low[kMaxN];
int inStack[kMaxN];
int dfn[kMaxN];
int head[kMaxN];
int tot = 0;
std::vector<int> stack;

void init_group() {
  memset(e, 0, sizeof(e));
  memset(head, 0, sizeof(head));
  tot = 0;
}

void add_edge(int u, int v) {
  e[++tot] = {v, head[u]};
  head[u] = tot;
}

void tarjan(int u) {
  using std::min;
  low[u] = dfn[u] = ++tot;
  stack.push_back(u);
  inStack[u] = true;
  for (int i = head[u]; i; i = e[i].next) {
    if (!dfn[e[i].v]) {
      tarjan(e[i].v);
      low[u] = min(low[u], low[e[i].v]);
    } else if (inStack[e[i].v]) {
      low[u] = min(low[u], dfn[e[i].v]);
    }
  }
  if (low[u] == dfn[u]) {
    int t;
    do {
      cout << (t = stack.back()) << " ";
      inStack[stack.back()] = false;
      stack.pop_back();
    } while (u != t);
    cout << endl;
  }
}

int n, m;
int a[kMaxN];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    add_edge(u, v);
  }
  tot = 0;
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i);
  }
  init_group();
  return 0;
}

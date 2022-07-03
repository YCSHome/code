#include <iostream>

using namespace std;

const int kMaxN = 1e6;

struct edge {
  int v, next;
}e[kMaxN];

int tot = 0;
int head[kMaxN];

void add(int u, int v) {
  e[++tot] = {v, head[u]};
  head[u] = tot;
}

int n, m;
int s, t;
int w[kMaxN];
int father[32][kMaxN];
int depth[kMaxN];
bool vis[kMaxN];

void build(int t, int f) {
  if (vis[t]) return;
  vis[t] = true;
  depth[t] = depth[f] + 1;
  father[0][t] = f;
  for (int i = 1; (1 << i) <= depth[t]; i++) {
    father[i][t] = father[i - 1][father[i - 1][t]];
  }
  for (int i = head[t]; i; i = e[i].next) {
    build(e[i].v, t);
  }
}

int LCA(int x, int y) {
  if (depth[x] < depth[y]) {
    swap(x, y);
  }
  for (int i = 20; i >= 0; i--) {
    if (depth[father[i][x]] >= depth[y]) {
      x = father[i][x];
    }
  }
  if (x == y) return x;
  for (int i = 20; i >= 0; i--) {
    if (father[i][x] != father[i][y]) {
      x = father[i][x];
      y = father[i][y];
    }
  }
  return father[0][x];
}

int main() {
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int s, t;
    cin >> s >> t;
    add(s, t);
    add(t, s);
  }
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  build(1, 0);
  for (int i = 1; i <= m; i++) {
    int s, t, p;
    cin >> s >> t;
    p = LCA(s, t);
    cout << p << endl;
  }
  return 0;
}

/*
 *     1
 *    / \
 *   4   2
 *  / \   \
 * 5   6   3
 */

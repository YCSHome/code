#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

struct edge {
  int v, next;
}e[MAXN];

int n;
int a[MAXN];
int head[MAXN];
int value[MAXN];
int tot = 0;
int d[MAXN];
int father[MAXN][30];
bool vis[MAXN];
vector<int> son[MAXN];

void add(int u, int v) {
  e[++tot] = {v, head[u]};
  head[u] = tot;
}

void add(int x, int y, int k) {
  value[x] += k;
  for (int i : son[y]) {
    value[i] -= k;
  }
}

void init(int u, int fa) {
  if (vis[u]) {
    return;
  }
  vis[u] = true;
  father[u][0] = fa;
  d[u] = d[fa] + 1;
  for (int i = 1; i < 30; i++) {
    father[u][i] = father[father[u][i - 1]][i - 1];
  }
  for (int i = head[u]; i; i = e[i].next) {
    init(e[i].v, u);
    son[u].push_back(e[i].v);
  }
}

int find(int x, int y) {
  if (d[x] > d[y]) {
    swap(x, y);
  }
  for (int i = 29; i >= 0; i--) {
    if (d[father[y][i]] >= d[x]) {
      y = father[y][i];
    }
  }
  if (x == y) return x;
  for (int i = 29; i >= 0; i--) {
    if (father[x][i] != father[y][i]) {
      x = father[x][i];
      y = father[y][i];
    }
  }
  return father[x][0];
}

void ans(int u) {
  vis[u] = true;
  for (int i = head[u]; i; i = e[i].next) {
    if (vis[e[i].v]) continue;
    ans(e[i].v);
    value[u] += value[e[i].v];
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    add(u, v);
    add(v, u);
  }
  init(1, 0);
  for (int i = 1; i < n; i++) {
    int x = a[i];
    int y = a[i + 1];
    int fa = find(x, y);
    value[x]++;
    value[y]++;
    value[fa]--;
    value[father[fa][0]]--;
  }
  memset(vis, false, sizeof(vis));
  ans(1);
  for (int i = 2; i <= n; i++) value[a[i]]--;
  for (int i = 1; i <= n; i++) {
    cout << value[i] << endl;
  }
  return 0;
}

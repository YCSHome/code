#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int kMaxN = 1e6;

struct edge {
  int v, next;
}e[kMaxN];

int head[kMaxN];
int edgeTotal = 0;
bool cut[kMaxN];

void add(int u, int v) {
  e[++edgeTotal] = {v, head[u]};
  head[u] = edgeTotal;
}

int n, m;
int low[kMaxN];
int dfn[kMaxN];
int top[kMaxN];
int size[kMaxN];
bool lock[kMaxN];
int tot = 0;
int AnsA;
int cuts = 0;
int c = 0;
int leaf = 0;

void tarjan(int x, int top) {
  low[x] = dfn[x] = ++tot;
  int son = 0;
  for (int i = head[x]; i; i = e[i].next) {
    int v = e[i].v;
    if (!dfn[v]) {
      tarjan(v, top);
      son++;
      low[x] = min(low[x], low[v]);
      if (low[v] >= dfn[x]) {
        if (x != top || son > 1) cut[x] = true;
      }
    } else {
      low[x] = min(low[x], dfn[v]);
    }
  }
  cuts += cut[x];
}

int get(int x) {
  if (cut[x] && lock[x] == false) {
    return -1e7;
  }
  if (dfn[x]) return 0;
  if (cut[x]) return 0;
  int size = 1;
  dfn[x] = 1;
  for (int i = head[x]; i; i = e[i].next) {
    size += get(e[i].v);
  }
  return size;
}

int t = 0;

bool solve() {
  t++;
  n = 0;
  tot = 0;
  cuts = 0;
  AnsA = 0;
  memset(e, 0, sizeof(e));
  memset(cut, 0, sizeof(cut));
  memset(low, 0, sizeof(low));
  memset(dfn, 0, sizeof(dfn));
  memset(head, 0, sizeof(head));
  cin >> m;
  if (m == 0) return false;
  cout << "Case " << t << ": ";
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    add(x, y);
    add(y, x);
    n = max(n, max(x, y));
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) {
      tarjan(i, i);
    }
  }
  if (cuts == 0) {
    cout << 2 << " " << (n - 1 == m ? 2 : n * (n - 1) / 2) << endl;
    return true;
  }
  memset(dfn, 0, sizeof(dfn));
  long long ans = 1, ans1 = 0;
  for (int i = 1; i <= n; i++) {
    if (cut[i]) {
      lock[i] = true;
      for (int j = head[i]; j; j = e[j].next) {
        int v = e[j].v, s;
        if ((s = get(v)) <= 0) {
        } else {
          ans *= s;
          ans1++;
        }
      }
      lock[i] = false;
    }
  }
  cout << ans1 << " " << ans << endl;
  return true;
}

int main() {
  while (solve());
}

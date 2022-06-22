#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e6;

int n, m;
vector<int> go[kMaxN];
long long ans[kMaxN];
bool cut[kMaxN];
int dfn[kMaxN];
int low[kMaxN];
int size[kMaxN];
int tot = 0;

void tarjan(int x) {
  dfn[x] = low[x] = ++tot;
  size[x] = 1;
  int son = 0, sum = 0;
  for (auto v : go[x]) {
    if (!dfn[v]) {
      tarjan(v);
      size[x] += size[v];
      low[x] = min(low[x], low[v]);
      if (low[v] >= dfn[x]) {
        ans[x] += (long long)size[v] * (n - size[v]);
        sum += size[v];
        son++;
        if (son > 1 || x != 1) cut[x] = true;
      }
    }
    else low[x] = min(dfn[v], low[x]);
  }
  if (!cut[x]) {
    ans[x] = 2 * (n - 1);
  } else {
    ans[x] += (long long)(n - sum - 1) * (sum + 1) + (n - 1);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    go[x].push_back(y);
    go[y].push_back(x);
  }
  tarjan(1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}

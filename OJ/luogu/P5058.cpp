#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e6;

vector<int> go[kMaxN];

int n;
int a, b;
int low[kMaxN];
int dfn[kMaxN];
int tot = 0;
int ans = 1e9;

void tarjan(int x) {
  low[x] = dfn[x] = ++tot;
  for (auto v : go[x]) {
    if (!dfn[v]) {
      tarjan(v);
      low[x] = min(low[x], low[v]);
      if (low[v] >= dfn[x] && x != a && x != b && 
          dfn[b] >= dfn[v]) {
        ans = min(ans, x);
      }
    } else {
      low[x] = min(low[x], dfn[v]);
    }
  }
}

int main() {
  cin >> n;
  int x, y;
  do {
    cin >> x >> y;
    go[x].push_back(y);
    go[y].push_back(x);
  } while(x != 0 || y != 0);
  cin >> a >> b;
  tarjan(a);
  if (ans == 1e9) {
    cout << "No solution" << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}

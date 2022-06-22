#include <iostream>
#include <algorithm>

using namespace std;

const int kMaxN = 1e6;

struct edge {
  int u, v, w;
}e[kMaxN];

int n, m, k;
int father[kMaxN];

int find(int x) {
  if (father[x] == x) {
    return x;
  }
  return father[x] = find(father[x]);
}

int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    father[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> e[i].u >> e[i].v >> e[i].w;
  }
  sort(e + 1, e + 1 + m, [](const auto& a, const auto& b) { return a.w > b.w; } );
  int tot = 0, ans = 0;
  for (int i = 1; i <= m && tot < k; i++) {
    int u = e[i].u, v = e[i].v;
    if (find(u) != find(v)) {
      father[find(u)] = find(v);
      ans += e[i].w;
      tot++;
    }
  }
  cout << ans << endl;
  return 0;
}

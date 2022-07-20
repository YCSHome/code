#include <bits/stdc++.h>
#define mid ((l + r) >> 1)
#define ll long long
#define maxn 100001
#define maxt 1000100
using namespace std;
int t[maxn], p[maxn];
int d[maxn], x[maxn];
vector<int> g[maxn];
ll ans[maxn];
ll T;
int n;
struct BT {
  ll t[maxn << 4];
  void add(int x, ll v) {
    while (x < maxt) t[x] += v, x += (x & -x);
  }
  ll sum(int x) {
    ll r = 0;
    while (x) r += t[x], x -= (x & -x);
    return r;
  }
} st, pt;
void Dfs(int u, ll dis) {
  ll cur = T - 2 * dis;
  st.add(t[u], 1ll * x[u] * t[u]);
  pt.add(t[u], x[u]);
  int l = 0, r = maxt - 1, res = 0;
  while (l <= r) {
    if (st.sum(mid) <= cur)
      res = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  if (res) ans[u] = pt.sum(res), cur -= st.sum(res);
  r = maxt - 1, res = 0;
  while (l <= r) {
    if (pt.sum(mid) != ans[u])
      res = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  if (res) ans[u] += cur / res;
  for (auto v : g[u]) Dfs(v, dis + d[v]);
  st.add(t[u], -1ll * x[u] * t[u]);
  pt.add(t[u], -x[u]);
  ll mx = 0;
  int nxt = 0;
  for (auto v : g[u])
    if (ans[v] > mx) mx = ans[v], nxt = v;
  if (u == 1) {
    ans[u] = max(ans[u], mx);
    return;
  }
  mx = 0;
  for (auto v : g[u])
    if (ans[v] > mx && v != nxt) mx = max(mx, ans[v]);
  ans[u] = max(ans[u], mx);
}
int main() {
  cin >> n >> T;
  for (int i = 1; i <= n; ++i) cin >> x[i];
  for (int i = 1; i <= n; ++i) cin >> t[i];
  for (int i = 2; i <= n; ++i) cin >> p[i] >> d[i], g[p[i]].push_back(i);
  Dfs(1, 0);
  cout << ans[1] << endl;
  return 0;
}

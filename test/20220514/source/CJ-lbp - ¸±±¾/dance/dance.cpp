#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 5, K = 2e5 + 5;

int n, k, m, p[N], a[K], b[K], ans[N], q[N];
vector<int> v[N], w[N], wv[N];
bool vis[N];

signed main() {
  freopen("dance.in", "r", stdin);
  freopen("dance.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k >> m;
  for (int i = 1; i <= n; ++i) p[i] = i, v[i].emplace_back(i), w[i].emplace_back(i);
  for (int i = 1; i <= k; ++i)
    cin >> a[i] >> b[i];
  for (int i = 1; i <= m % k; ++i)
    v[p[a[i]]].emplace_back(b[i]), v[p[b[i]]].emplace_back(a[i]), w[p[a[i]]].emplace_back(b[i]), w[p[b[i]]].emplace_back(a[i]), swap(p[a[i]], p[b[i]]);
  for (int i = m % k + 1; i <= k; ++i)
    wv[p[a[i]]].emplace_back(b[i]), wv[p[b[i]]].emplace_back(a[i]), w[p[a[i]]].emplace_back(b[i]), w[p[b[i]]].emplace_back(a[i]), swap(p[a[i]], p[b[i]]);
  for (int i = 1; i <= n; ++i) q[p[i]] = i;
  for (int i = 1; i <= n; ++i) p[i] = q[i];
  m /= k;
  if (m == 0) {
    for (int i = 1; i <= n; ++i)
      sort(v[i].begin(), v[i].end()), v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
    for (int i = 1; i <= n; ++i) cout << v[i].size() << '\n';
    return 0;
  }
  for (int i = 1; i <= n; ++i) if (!vis[i]) {
    vector<int> cir(0);
    int cur = i;
    while (!vis[cur]) cir.emplace_back(cur), vis[cur] = 1, cur = p[cur];
    multiset<int> s;
    set<int> ss;
    if (m >= cir.size()) {
      set<int> s;
      for (int t : cir) for (int tt : w[t]) s.insert(tt);
      for (int t : cir) ans[t] = s.size();
      continue;
    }
    int c = m;
    for (int j = 0; j < c; ++j) for (int t : w[cir[j]]) s.insert(t), ss.insert(t);
    for (int t : v[cir[c % cir.size()]]) s.insert(t), ss.insert(t);
    for (int j = 0; j < cir.size(); ++j) {
      ans[cir[j]] = ss.size();
      for (int t : w[cir[j]]) {
        s.erase(s.find(t));
        if (!s.count(t)) ss.erase(t);
      }
      for (int t : wv[cir[(j + c) % cir.size()]]) s.insert(t), ss.insert(t);
      for (int t : v[cir[(j + c + 1) % cir.size()]]) s.insert(t), ss.insert(t);
    }
  }
  for (int i = 1; i <= n; ++i) cout << ans[i] << '\n';
  return 0;
}

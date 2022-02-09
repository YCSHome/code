#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define drep(i, s, e) for (int i = s; i >= e; --i)
#define file(a) freopen(#a ".in", "r", stdin), freopen(#a ".out", "w", stdout)

const int N = 1005;

using ll = long long;

int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return x * f;
}

int n, vis[N];
ll x[N], w[N];

int bfs(int s, ll t) {
  int res = 1;
  queue<int> q;
  rep(i, 1, n) vis[i] = 0, w[i] = 0;
  q.push(s), vis[s] = 1, w[s] = t;
  while (q.size()) {
    int u = q.front();
    q.pop();
    if (u >= s) {
      int v = u;
      while (v < n && x[v + 1] - x[u] <= w[u]) ++v, ++res;
      if (v != u) w[v] = (w[u] * 2) / 3, q.push(v);
    }
    if (u <= s) {
      int v = u;
      while (v > 1 && x[u] - x[v - 1] <= w[u]) --v, ++res;
      if (v != u) w[v] = (w[u] * 2) / 3, q.push(v);
    }
  }
  return res;
}

bool check(ll t) {
  rep(i, 1, n) if (bfs(i, t) == n) return true;
  return false;
}

int main() {
  file(bomb);
  n = read();
  rep(i, 1, n) x[i] = read();
  sort(x + 1, x + 1 + n);
  ll l = 1, r = 1e18;
  while (l < r) {
    ll mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%lld\n", l);
  return 0;
}
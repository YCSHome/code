#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, e) for (int i = s; i <= e; ++i)
#define drep(i, s, e) for (int i = s; i >= e; --i)
#define file(a) freopen(#a ".in", "r", stdin), freopen(#a ".out", "w", stdout)

using ll = long long;

const int N = 1e6 + 10;

int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - 48;
  return x * f;
}

int n, m, p, fa[N], sz[N], d[N];

int get(int u) {
  int res = 0, v = u;
  while (fa[v] != v) res = (res + d[v]) % p, v = fa[v];
  fa[u] = v, d[u] = res;
  return v;
}

int dis(int u) {
  int res = 0;
  while (fa[u] != u) res = (res + d[u]) % p, u = fa[u];
  return res;
}

void merge(int u, int v, int val) {
  val = (val + dis(u)) % p, val = (val - dis(v) + p) % p;
  u = get(u), v = get(v), d[v] = val, fa[v] = u;
}

int main() {
  file(seq);
  n = read(), m = read(), p = read();
  rep(i, 0, n) fa[i] = i;
  rep(i, 1, m) {
    int u = read() - 1, v = read(), k = read();
    if (get(u) != get(v))
      merge(v, u, k);
    else {
      if ((dis(v) - dis(u) + p) % p == k) continue;
      return printf("%d\n", i - 1, 0), 0;
    }
  }
  printf("%d\n", m);
  return 0;
}

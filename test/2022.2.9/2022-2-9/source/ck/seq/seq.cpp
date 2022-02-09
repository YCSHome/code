#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define drep(i, s, e) for (int i = s; i >= e; --i)
#define file(a) freopen(#a ".in", "r", stdin), freopen(#a ".out", "w", stdout)

const int N = 1000000 + 5;

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

int n, m, p, ans, f[N], w[N];

int inc(int a, int b) { return (a += b) < p ? a : a - p; }
int dec(int a, int b) { return (a -= b) < 0 ? a + p : a; }

int get(int x) {
  if (x == f[x]) return x;
  int u = f[x];
  f[x] = get(f[x]), w[x] = inc(w[x], w[u]);
  return f[x];
}

int main() {
  file(seq);
  n = read(), m = read(), p = read();
  rep(i, 1, n + 1) f[i] = i;
  rep(i, 1, m) {
    int l = read(), r = read(), v = read();
    int fx = get(l), fy = get(r + 1);
    if (fx != fy) {
      w[fx] = inc(dec(v, w[l]), w[r + 1]);
      f[fx] = fy;
    } else {
      if (dec(w[l], w[r + 1]) != v) {
        rep(j, i + 1, m) read(), read(), read();
        break;
      }
    }
    ++ans;
  }
  printf("%d\n", ans);
  return 0;
}
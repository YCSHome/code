#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, e) for (int i = s; i <= e; ++i)
#define drep(i, s, e) for (int i = s; i >= e; --i)
#define file(a) freopen(#a ".in", "r", stdin), freopen(#a ".out", "w", stdout)

const int N = 1e5 + 10;

int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - 48;
  return x * f;
}

int n, m, k, ans, lx[N], rx[N], ly[N], ry[N];
vector<int> a[N], s[N];
bool ban[N];

void upd(int i, int j, int c) {
  lx[c] = min(lx[c], i), rx[c] = max(rx[c], i);
  ly[c] = min(ly[c], j), ry[c] = max(ry[c], j);
}

int main() {
  file(paint);
  n = read(), m = read(), k = read(), ans = k;
  if (n == 1 && m == 1) return printf("%d\n", k - 1), 0;
  rep(i, 1, k) lx[i] = n + 1, rx[i] = 0, ly[i] = m + 1, ry[i] = 0;
  rep(i, 1, n) {
    a[i].resize(m + 1);
    rep(j, 1, m) {
      a[i][j] = read();
      if (a[i][j]) upd(i, j, a[i][j]);
    }
  }
  rep(i, 0, n + 10) s[i].resize(m + 10);
  rep(i, 1, k) {
    if (lx[i] == n + 1) continue;
    ++s[lx[i]][ly[i]], --s[lx[i]][ry[i] + 1], --s[rx[i] + 1][ly[i]],
        ++s[rx[i] + 1][ry[i] + 1];
  }
  rep(i, 1, n) {
    rep(j, 1, m) {
      s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
      if (s[i][j] > 1) {
        if (!ban[a[i][j]]) --ans, ban[a[i][j]] = true;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}

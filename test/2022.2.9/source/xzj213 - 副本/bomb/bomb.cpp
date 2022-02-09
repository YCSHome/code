#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int l[maxn], r[maxn], n, d[maxn], q[maxn];
/*
f-------将前面所有炸弹引爆需要的能量
g-------将后面所有炸弹引爆需要的能量
*/
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int calc(int x, int y) { return max(abs(d[x] - d[y]), (l[x] * 3 + 1) >> 1); }
int calc1(int x, int y) { return max(abs(d[x] - d[y]), (r[x] * 3 + 1) >> 1); }
signed main() {
  freopen("bomb.in", "r", stdin);
  freopen("bomb.out", "w", stdout);
  n = read();
  for (int i = 1; i <= n; i++) d[i] = read();
  sort(d + 1, d + 1 + n);
  memset(l, 0x3f, sizeof(l));
  memset(r, 0x3f, sizeof(r));
  l[0] = 0;
  int hd = 0, tl = 1;
  q[++hd] = 1;
  for (int i = 2; i <= n; i++) {
    while (hd < tl && calc(q[hd], i) >= calc(q[hd + 1], i)) hd++;
    int j = q[hd];
    l[i] = calc(j, i);
    while (hd < tl && calc(q[tl], i) >= ((l[i] * 3 + 1) >> 1)) tl--;
    q[++tl] = i;
  }
  r[n + 1] = 0;
  hd = 0, tl = 1;
  q[++hd] = n;
  for (int i = n - 1; i >= 1; i--) {
    while (hd < tl && calc1(q[hd], i) >= calc1(q[hd + 1], i)) hd++;
    int j = q[hd];
    r[i] = calc1(j, i);
    while (hd < tl && calc1(q[tl], i) >= ((r[i] * 3 + 1) >> 1)) tl--;
    q[++tl] = i;
  }
  int ans = 0x3f3f3f3f3f3f3f3f;
  for (int i = 1; i <= n; i++) ans = min(ans, max(l[i], r[i]));
  cout << ans << endl;
  return 0;
}
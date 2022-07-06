#include <bits/stdc++.h>
#define rei register int
#define pb push_back
#define er pop_back
using namespace std;
const int maxn = 100010;
struct segment {
  int c, l, r;
};
int T;
int n;
segment a[maxn];
int st[2][maxn];
int tp[2];
int fa[maxn];
int getf(int x) {
  if (fa[x] != x)
    return fa[x] = getf(fa[x]);
  return x;
}
bool cmp(segment x, segment y) {
  if (x.l == y.l)
    return x.r < y.r;
  else
    return x.l < y.l;
}
int main() {
  cin >> T;
  while (T--) {
    scanf("%d", &n);
    for (rei i = 1; i <= n; ++i)
      fa[i] = i;
    for (rei i = 1; i <= n; ++i) {
      scanf("%d%d%d", &a[i].c, &a[i].l, &a[i].r);
    }
    sort(a + 1, a + 1 + n, cmp);
    tp[0] = tp[1] = 0;
    for (rei i = 1; i <= n; ++i) {
      int C = a[i].c;
      int j = C ^ 1;
      int maxr = -1, maxp = -1;
      for (rei k = 1; k <= tp[j]; ++k)
        if (a[st[j][k]].r >= a[i].l) {
          int x = st[j][k], y = i;
          if (a[x].r > maxr)
            maxr = a[x].r, maxp = x;
          int fx = getf(x);
          int fy = getf(y);
          fa[fy] = fx;
        }
      if (maxr != -1) {
        tp[j] = 1;
        st[j][1] = maxp;
      }
      st[C][++tp[C]] = i;
    }
    int ans = 0;
    for (rei i = 1; i <= n; ++i) {
      if (fa[i] == i)
        ++ans;
    }
    printf("%d\n", ans);
  }
  return 0;
}

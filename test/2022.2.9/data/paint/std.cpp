#include <bits/stdc++.h>
#define M 100010
#define p(a, b) (a * mm + b - mm)
using namespace std;
int i, j, Li[M], Ri[M], Lj[M], Rj[M], a[M], use[M], ans, n, m, K, fl, nxt[M],
    pre[M], vis[M], mm, u;
int find(int x) {
  if (!vis[x]) return x;
  return nxt[x] = find(nxt[x]);
}
int main() {
  fl = 0;
  scanf("%d%d%d", &n, &m, &K);
  memset(Li, 63, sizeof(Li));
  memset(Lj, 63, sizeof(Lj));
  memset(Ri, 0, sizeof(Ri));
  memset(Rj, 0, sizeof(Rj));
  memset(use, 0, sizeof(use));
  mm = max(n, m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (n > m)
        u = p(j, i);
      else
        u = p(i, j);
      scanf("%d", &a[u]);
    }
  if (n > m) swap(n, m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      u = p(i, j);
      nxt[u] = p(i, j + 1);
      pre[u] = p(i, j - 1);
      if (Ri[a[u]] == 0 && a[u]) fl++;
      if (i < Li[a[u]]) Li[a[u]] = i;
      if (i > Ri[a[u]]) Ri[a[u]] = i;
      if (j < Lj[a[u]]) Lj[a[u]] = j;
      if (j > Rj[a[u]]) Rj[a[u]] = j;
    }
  for (int i = 1; i <= K; i++)
    if (Li[i] <= Ri[i]) {
      for (int j = Li[i]; j <= Ri[i]; j++)
        for (int k = Lj[i]; k <= Rj[i]; k = find(nxt[k]))
          if (a[p(j, k)] != i) {
            use[a[p(j, k)]] = 1;
            vis[p(j, k)] = 1;
            nxt[pre[p(j, k)]] = nxt[p(j, k)];
            pre[nxt[p(j, k)]] = pre[p(j, k)];
          }
    }
  for (int i = 1; i <= K; i++)
    if (!use[i]) ans++;
  if (ans == K && fl == 1 && ans > 1) ans--;
  if (fl)
    printf("%d\n", ans);
  else
    puts("0");
}

#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = l; i <= r; i++)
#define dep(i, r, l) for (int i = r; i >= l; i--)

const int N = 1e5 + 10;

int n, m, k, a[N], b[N], c[N], d[N], tag[N], ans;
vector<int> col[N], sum[2][N];

int main() {
  freopen("paint.in", "r", stdin);
  freopen("paint.out", "w", stdout);

  scanf("%d%d%d", &n, &m, &k);
  rep(p, 0, 1) rep(i, 0, n + 2) rep(j, 0, m + 2) sum[p][i].push_back(0);
  for (int color, i = 1; i <= n; i++) {
    col[i].push_back(0);
    rep(j, 1, m) scanf("%d", &color), col[i].push_back(color);
  }

  int num = 0;
  rep(i, 1, n) rep(j, 1, m) if (!tag[col[i][j]]) tag[col[i][j]] = true, num++;
  if (num == 1) return printf("%d\n", k - 1), 0;
  memset(tag, false, sizeof tag);
  // 如果总共只出现过一种颜色，那么答案为 k - 1.
  // 没有出现过的颜色一定可以作为最先使用的。

  rep(i, 0, k) a[i] = b[i] = c[i] = d[i] = -1;
  rep(i, 1, n) rep(j, 1, m) {
    if (a[col[i][j]] == -1)
      a[col[i][j]] = i;
    else
      a[col[i][j]] = min(a[col[i][j]], i);
    if (c[col[i][j]] == -1)
      c[col[i][j]] = i;
    else
      c[col[i][j]] = max(c[col[i][j]], i);
    if (b[col[i][j]] == -1)
      b[col[i][j]] = j;
    else
      b[col[i][j]] = min(b[col[i][j]], j);
    if (d[col[i][j]] == -1)
      d[col[i][j]] = j;
    else
      d[col[i][j]] = max(d[col[i][j]], j);
  }
  // 可以发现矩形的大小越小越好，于是考虑处理出矩形的最小大小。

  /*--------------------------------------------------------------------
  观察到一个矩形如果将其它矩形覆盖过，那么它一定不能成为答案。
  于是考察每一个颜色的矩形，如果在它覆盖的区域还有其它颜色，那么那个颜色
  一定不合法。换而言之，我们需要维护一个操作，即将一个矩形内除了某种颜色
  之外的所有颜色打上不合法标记。
  考虑按位处理，二维前缀和维护，时间复杂度 O[(nm + k) log nm].
  （事实上还可以随机化，可以做到 O[T(nm + k)]，T 为随机次数，毛估估一下大概 3 -
  4 ?）
  ---------------------------------------------------------------------*/

  rep(t, 0, 17) {
    rep(p, 0, 1) rep(i, 0, n + 2) rep(j, 0, m + 2) sum[p][i][j] = 0;
    rep(i, 1, k) if (a[i] != -1) {
      int p = ((i >> t) & 1) ^ 1;
      sum[p][a[i]][b[i]]++, sum[p][c[i] + 1][d[i] + 1]++;
      sum[p][c[i] + 1][b[i]]--, sum[p][a[i]][d[i] + 1]--;
    }
    rep(p, 0, 1) rep(i, 1, n) rep(j, 1, m) sum[p][i][j] +=
        sum[p][i - 1][j] + sum[p][i][j - 1] - sum[p][i - 1][j - 1];
    rep(i, 1, n) rep(j, 1, m) if (sum[(col[i][j] >> t) & 1][i][j] > 0)
        tag[col[i][j]] = true;
  }

  ans = k;
  rep(i, 1, k) ans -= tag[i];
  printf("%d\n", ans);

  return 0;
}
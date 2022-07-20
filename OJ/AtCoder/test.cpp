#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = (x); i <= (y); i++)
#define down(i, x, y) for (int i = (x); i >= (y); i--)
#define full(x, y) memset(x, y, sizeof(x))
typedef long long ll;
const int maxn = 1e5 + 10;
const int maxb = 320;

int n, q;
ll mx, a[maxn], b[maxn], mp[maxn];
ll num, block, l[maxb], r[maxb], bel[maxn], f[maxb][maxb], cnt[maxb][maxn];

inline int read()
{
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9')
  {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
  {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

//预处理出每块间的最大重要度
//需要注意的是a是离散化后的数组，在计算重要度的时候要记得还原
void init()
{
  rep(i, 1, num)
  {
    mx = 0;
    rep(j, l[i], n)
    {
      mp[a[j]]++;
      mx = std::max(mx, mp[a[j]] * b[a[j]]);
      f[i][bel[j]] = mx;
    }
    full(mp, 0);
  }
}

void build()
{
  block = sqrt(n);
  num = (n - 1) / block + 1;
  rep(i, 1, n) bel[i] = (i - 1) / block + 1, cnt[bel[i]][a[i]]++;
  rep(i, 1, num) l[i] = (i - 1) * block + 1, r[i] = i * block;
  r[num] = n;
  //预处理出前i块中j的出现次数
  rep(i, 1, num) rep(j, 1, n) cnt[i][j] += cnt[i - 1][j];
}

ll query(int ql, int qr)
{
  int bl = bel[ql], br = bel[qr];
  ll res = 0;
  if (bl ^ br)
  {
    if (bl + 1 <= br - 1)
      res = f[bl + 1][br - 1];
    rep(i, ql, r[bl])
    {
      mp[a[i]]++;
      mx = (mp[a[i]] + cnt[br - 1][a[i]] - cnt[bl][a[i]]) * b[a[i]];
      res = std::max(res, mx);
    }
    rep(i, l[br], qr)
    {
      mp[a[i]]++;
      mx = (mp[a[i]] + cnt[br - 1][a[i]] - cnt[bl][a[i]]) * b[a[i]];
      res = std::max(res, mx);
    }
    full(mp, 0);
  }
  else
  {
    rep(i, ql, qr)
    {
      mp[a[i]]++;
      res = std::max(res, mp[a[i]] * b[a[i]]);
    }
    full(mp, 0);
  }
  return res;
}

int main(int argc, char const *argv[])
{
  using std::cout;
  using std::endl;
  n = read(), q = read();
  rep(i, 1, n) a[i] = b[i] = read();
  std::sort(b + 1, b + n + 1);
  int m = std::unique(b + 1, b + n + 1) - b - 1;
  rep(i, 1, n) a[i] = std::lower_bound(b + 1, b + n + 1, a[i]) - b; //离散化
  build(), init();
  int ql, qr;
  cout << f[2][2] << endl << f[2][3] << endl << f[2][4] << endl << f[2][5] << endl << f[2][6] << endl;
  rep(i, 1, q)
  {
    ql = read(), qr = read();
    printf("%lld\n", query(ql, qr));
  }
  return 0;
}


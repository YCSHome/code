#include <bits/stdc++.h>
#define ll long long
#define db double
#define filein(a) freopen(#a ".in", "r", stdin)
#define fileot(a) freopen(#a ".out", "w", stdout)
#define wash fflsuh(stdout)
#define sky return
template <class T>
inline void read(T &s) {
  s = 0;
  char ch = getchar();
  bool f = 0;
  while (ch < '0' || '9' < ch) {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    s = s * 10 + (ch ^ 48);
    ch = getchar();
  }
  if (ch == '.') {
    db p = 0.1;
    ch = getchar();
    while ('0' <= ch && ch <= '9') {
      s = s + (ch ^ 48) * p;
      ch = getchar();
    }
  }
  s = f ? -s : s;
}
const int N = 1e6 + 3;
const int eps = 1e-9;
const ll inf = 1e18;
inline int sgn(int x) { sky x < -eps ? -1 : x < eps ? 0 : 1; }
int n;
ll p[N];
std::mt19937 rd(time(0));
int ap, np;
ll nw, aw;
inline db qpow(db a, int b) {
  db ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}
db tt23[N];
inline ll calc(int a) {
  ll ans = 0;
  if (a != 1) {
    ll maxn = 0;
    for (int i = 1; i < a; ++i) {
      if ((p[i + 1] - p[i]) * tt23[a - i - 1] > maxn) {
        maxn = (ll)std::ceil(1ll * (p[i + 1] - p[i]) * tt23[a - i - 1]);
      }
    }
    // if(a==3) printf("   %lld\n",maxn);
    ans = std::max(ans, maxn);
  }
  if (a != n) {
    ll maxn = 0;
    for (int i = n - 1; i >= a; --i) {
      if ((p[i + 1] - p[i]) * tt23[i - a + 1] > maxn) {
        maxn = (ll)std::ceil(1ll * (p[i + 1] - p[i]) * tt23[i - a + 1]);
      }
    }
    // if(a==3) printf("   %lld\n",maxn);
    ans = std::max(ans, maxn);
  }
  sky ans;
}
inline void SA() {
  double tem = 1, dt = 0.99799, ted = 1e-6;
  np = ap;
  nw = aw;
  while (tem > ted) {
    int pt = np;
    np = (1ll * np + (ll)(rd() * tem)) % n + 1;
    // printf("Reach! %d\n",np);
    nw = calc(np);
    double delta = nw - aw;
    // printf("%lld %lld %lf\n",aw,nw,tem);
    if (delta < 0) {
      aw = nw;
      ap = np;
    } else {
      if (exp(-delta / tem) <= (db)rd() / (db)UINT_MAX) {
        np = pt;
      }
    }
    tem *= dt;
    if (clock() > 1900) return;
  }
}
ll sum[N];
int main() {
  filein(bomb);
  fileot(bomb);
  read(n);
  tt23[0] = 1;
  tt23[1] = 1.5;
  for (int i = 1; i <= n; ++i) {
    read(p[i]);
    if (i > 1) tt23[i] = tt23[i - 1] * tt23[1];
    sum[i] = sum[i - 1] + p[i];
  }
  std::sort(p + 1, p + 1 + n);
  p[n + 1] = inf;
  ll minn = inf;
  for (int i = 1; i <= n; ++i) {
    if (sum[n] - sum[i] - sum[i] < minn) {
      minn = sum[n] - sum[i] - sum[i];
      ap = i;
    }
  }
  aw = calc(ap);
  if (n > (int)1e4) {
    while (clock() < 1900) {
      SA();
    }
    printf("%lld\n", aw);
    sky 0;
  }
  for (int i = 1; i <= n; ++i) {
    aw = std::min(aw, calc(i));
  }
  printf("%lld\n", aw);
  // printf("%lld\n",calc(3) );
  // printf("%dms",clock() );
  sky 0;
}
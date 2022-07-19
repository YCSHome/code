#include <algorithm>
#include <cstdio>
#include <cstring>
#define rint int
using namespace std;
typedef long long ll;
const int N = 5e4 + 5;
struct Ask {
  int op, l, r, id;
  ll v;
} q[N], tl[N], tr[N];
int tag[N << 2], rec[N << 2], ans[N];
ll sum[N << 2];
int n, m, Q;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
#define lc p << 1
#define rc p << 1 | 1
inline void pushdown(int p, int l, int r) {
  if (rec[p]) {
    rec[p] = 0;
    tag[lc] = tag[rc] = sum[lc] = sum[rc] = 0;
    rec[lc] = 1, rec[rc] = 1;
  }
  if (tag[p]) {
    rint mid = (l + r) >> 1;
    tag[lc] += tag[p], tag[rc] += tag[p];
    sum[lc] += tag[p] * (mid - l + 1);
    sum[rc] += tag[p] * (r - mid);
    tag[p] = 0;
  }
}
inline void add(int ql, int qr, int w, int p = 1, int l = 1, int r = n) {
  if (ql <= l && r <= qr) {
    tag[p] += w;
    sum[p] += w * (r - l + 1);
    return;
  }
  if (tag[p] || rec[p]) pushdown(p, l, r);
  rint mid = (l + r) >> 1;
  if (ql <= mid) add(ql, qr, w, lc, l, mid);
  if (mid < qr) add(ql, qr, w, rc, mid + 1, r);
  sum[p] = sum[lc] + sum[rc];
}
inline ll query(int ql, int qr, int p = 1, int l = 1, int r = n) {
  if (ql <= l && r <= qr) return sum[p];
  rint mid = (l + r) >> 1;
  ll tt = 0;
  if (tag[p] || rec[p]) pushdown(p, l, r);
  if (ql <= mid) tt += query(ql, qr, lc, l, mid);
  if (mid < qr) tt += query(ql, qr, rc, mid + 1, r);
  return tt;
}
inline void solve(int st, int en, int l, int r) {
  if (l == r) {
    for (rint i = st; i <= en; ++i)
      if (q[i].op == 2) ans[q[i].id] = l;
    return;
  }
  rint mid = (l + r) >> 1;
  bool fl = 0, fr = 0;
  rint L = 0, R = 0;
  rec[1] = 1;
  tag[1] = sum[1] = 0;
  for (rint i = st; i <= en; ++i)
    if (q[i].op == 1) {
      if (q[i].v > mid) {
        add(q[i].l, q[i].r, 1);
        tr[++R] = q[i];
      } else
        tl[++L] = q[i];
    } else {
      ll val = query(q[i].l, q[i].r);
      if (val < q[i].v) {
        q[i].v -= val;
        fl = 1;
        tl[++L] = q[i];
      } else {
        fr = 1;
        tr[++R] = q[i];
      }
    }
  for (rint i = 1; i <= L; ++i) q[st + i - 1] = tl[i];
  for (rint i = L + 1; i <= L + R; ++i) q[st + i - 1] = tr[i - L];
  if (fl) solve(st, st + L - 1, l, mid);
  if (fr) solve(st + L, en, mid + 1, r);
}
int main() {
  n = read(), m = read();
  for (rint i = 1; i <= m; ++i) {
    q[i].op = read(), q[i].l = read(), q[i].r = read(), q[i].v = read();
    if (q[i].op == 2) q[i].id = ++Q;
  }
  solve(1, m, -n, n);
  for (rint i = 1; i <= Q; ++i) printf("%d\n", ans[i]);
  return 0;
}

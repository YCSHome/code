#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#define int long long

using namespace std;

const int kMaxN = 4e6;

class BIT {
private:
  int a[kMaxN];
  inline int lowbit(int x) { return x & -x; }

public:
  inline void add(int x, int k) {
    for (; x < kMaxN; x += lowbit(x)) {
      a[x] += k;
    }
  }

  inline int get(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x)) {
      ans += a[x];
    }
    return ans;
  }
  inline void clear() { memset(a, 0, sizeof(a)); }
} t1, t2;

struct node {
  int value;
  int p, t, d;
  bool operator<(const node& cmp) const {
    if (value == cmp.value) {
      return t > cmp.t;
    }
    return value < cmp.value;
  }
} P[kMaxN];

int n, m, ans = 0;
int a[10][kMaxN];
vector<node> nodes;
const int Max = 4e5;

int getAns(int p, int q, int r) {
  int ans = 0, cnt = 0;
  t1.clear(), t2.clear();
  for (int i = 1; i <= n; ++i) {
    P[++cnt] = {a[p][i] - a[q][i] + Max, a[p][i] - a[r][i] + Max, 0, a[p][i]};
    P[++cnt] = {a[q][i] - a[p][i] + Max + 1, a[r][i] - a[p][i] + Max + 1, i, 0};
  }
  sort(P + 1, P + 1 + cnt);
  for (int i = 1; i <= cnt; ++i) {
    if (P[i].t)
      ans += a[p][P[i].t] * t1.get(P[i].p - 1) + t2.get(P[i].p - 1);
    else
      t1.add(P[i].p, 1), t2.add(P[i].p, P[i].d);
  }
  t1.clear(), t2.clear(), cnt = 0;
  for (int i = 1; i <= n; ++i) {
    P[++cnt] = {a[q][i] - a[p][i] + Max, a[q][i] - a[r][i] + Max, 0, a[q][i]};
    P[++cnt] = {a[p][i] - a[q][i] + Max, a[r][i] - a[q][i] + Max + 1, i, 0};
  }
  sort(P + 1, P + 1 + cnt);
  for (int i = 1; i <= cnt; ++i) {
    if (P[i].t)
      ans += a[q][P[i].t] * t1.get(P[i].p - 1) + t2.get(P[i].p - 1);
    else
      t1.add(P[i].p, 1), t2.add(P[i].p, P[i].d);
  }
  t1.clear(), t2.clear(), cnt = 0;
  for (int i = 1; i <= n; ++i) {
    P[++cnt]={a[r][i]-a[p][i]+Max,a[r][i]-a[q][i]+Max,0,a[r][i]};
    P[++cnt]={a[p][i]-a[r][i]+Max,a[q][i]-a[r][i]+Max,i,0};
  }
  sort(P + 1, P + 1 + cnt);
  for (int i = 1; i <= cnt; ++i) {
    if (P[i].t)
      ans += a[r][P[i].t] * t1.get(P[i].p - 1) + t2.get(P[i].p - 1);
    else
      t1.add(P[i].p, 1), t2.add(P[i].p, P[i].d);
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      a[i][j] = -a[i][j];
    }
  }
  t1.clear(), t2.clear(), cnt = 0;
  for (int i = 1; i <= n; ++i) {
    P[++cnt] = {a[p][i] - a[q][i] + Max, a[p][i] - a[r][i] + Max, 0, a[p][i]};
    P[++cnt] = {a[q][i] - a[p][i] + Max + 1, a[r][i] - a[p][i] + Max + 1, i, 0};
  }
  sort(P + 1, P + 1 + cnt);
  for (int i = 1; i <= cnt; ++i) {
    if (P[i].t)
      ans -= a[p][P[i].t] * t1.get(P[i].p - 1) + t2.get(P[i].p - 1);
    else
      t1.add(P[i].p, 1), t2.add(P[i].p, P[i].d);
  }
  t1.clear(), t2.clear(), cnt = 0;
  for (int i = 1; i <= n; ++i) {
    P[++cnt] = {a[q][i] - a[p][i] + Max, a[q][i] - a[r][i] + Max, 0, a[q][i]};
    P[++cnt] = {a[p][i] - a[q][i] + Max, a[r][i] - a[q][i] + Max + 1, i, 0};
  }
  sort(P + 1, P + 1 + cnt);
  for (int i = 1; i <= cnt; ++i) {
    if (P[i].t)
      ans -= a[q][P[i].t] * t1.get(P[i].p - 1) + t2.get(P[i].p - 1);
    else
      t1.add(P[i].p, 1), t2.add(P[i].p, P[i].d);
  }
  t1.clear(), t2.clear(), cnt = 0;
  for (int i = 1; i <= n; ++i) {
    P[++cnt] = {a[r][i] - a[p][i] + Max, a[r][i] - a[q][i] + Max, 0, a[r][i]};
    P[++cnt] = {a[p][i] - a[r][i] + Max, a[q][i] - a[r][i] + Max, i, 0};
  }
  sort(P + 1, P + 1 + cnt);
  for (int i = 1; i <= cnt; ++i) {
    if (P[i].t)
      ans -= a[r][P[i].t] * t1.get(P[i].p - 1) + t2.get(P[i].p - 1);
    else
      t1.add(P[i].p, 1), t2.add(P[i].p, P[i].d);
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      a[i][j] = -a[i][j];
    }
  }
  return ans;
}

signed main() {
  scanf("%lld%lld", &m, &n);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%lld", &a[i][j]);
    }
  }
  if (m == 2) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += a[1][i] + a[2][i];
    }
    printf("%lld", ans * n * 2);
  } else if (m == 3) {
    printf("%lld", getAns(1, 2, 3));
  } else {
    int ans = getAns(1, 2, 3) + getAns(1, 2, 4) + getAns(1, 3, 4) + getAns(2, 3, 4);
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        ans -= a[i][j] * 2 * n;
      }
    }
    printf("%lld", ans / 2);
  }
  return 0;
}

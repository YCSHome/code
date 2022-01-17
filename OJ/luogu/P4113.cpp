#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 2e6;

class BitTree {
private:
  long long lowbit(long long x) {
    return x & -x;
  }
  long long a[MAXN];

public:
  void add(long long x, long long y) {
    for (; x < MAXN; x += lowbit(x)) {
      a[x] += y;
    }
  }

  long long get(long long x) {
    long long ans = 0;
    for (; x; x -= lowbit(x)) {
      ans += a[x];
    }
    return ans;
  }
}tree;

struct que {
  long long id;
  long long l, r;
  bool operator<(const que& q) const {
    return r < q.r;
  }
}q[MAXN];

long long n, c, m;
long long a[MAXN];
long long ans[MAXN];
long long last1[MAXN], last2[MAXN];

int main() {
  scanf("%lld%lld%lld", &n, &c, &m);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  for (long long i = 1; i <= m; i++) {
    scanf("%lld%lld", &q[i].l, &q[i].r);
    q[i].id = i;
  }
  sort(q + 1,  q + 1 + m);
  for (long long i = 1, j = 1; i <= m; i++) {
    for (; j <= q[i].r; j++) {
      if (!last1[a[j]]) {
        last1[a[j]] = j;
      } else if (!last2[a[j]]) {
        last2[a[j]] = j;
        tree.add(last1[a[j]], 1);
      } else {
        tree.add(last2[a[j]], 1);
        tree.add(last1[a[j]], -1);
        last1[a[j]] = last2[a[j]];
        last2[a[j]] = j;
      }
    }
    ans[q[i].id] = tree.get(q[i].r) - tree.get(q[i].l - 1);
  }
  for (long long i = 1; i <= m; i++) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}

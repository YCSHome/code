#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1e6 + 100;

long long n;
int a[MAXN];
long long f[MAXN][2];

inline long long get(long long number) { return (number * 3 + 1) >> 1; }

inline long long get(long long x, long long y, long long opt) {
  return max((long long)abs(a[x] - a[y]), get(f[y][opt]));
}

#define update(opt)                                                        \
  while (head < end && get(i, q[head], opt) >= get(i, q[head + 1], opt)) { \
    head++;                                                                \
  }                                                                        \
  f[i][opt] = get(i, q[head], opt);                                        \
  while (head <= end && get(i, q[head], opt) >= get(i, i, opt)) {          \
    end--;                                                                 \
  }                                                                        \
  q[++end] = i;

long long q[MAXN];

namespace STD {
long long solve() {
  memset(f, 0, sizeof(f));
  long long head = 1;
  long long end = 0;
  q[++end] = 1;
  for (long long i = 2; i <= n; i++) {
    update(0);
  }
  head = 1;
  end = 0;
  q[++end] = n;
  for (long long i = n - 1; i >= 1; i--) {
    update(1);
  }
  long long ans = LLONG_MAX;
  for (long long i = 1; i <= n; i++) {
    ans = min(ans, max(f[i][0], f[i][1]));
  }
  return ans;
}
}  // namespace STD

int main() {
  freopen("bomb.in", "r", stdin);
  freopen("bomb.out", "w", stdout);
  srand(time(NULL));
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  sort(a + 1, a + 1 + n);
  n = unique(a + 1, a + 1 + n) - a - 1;
  f[1][0] = f[1][1] = 0;
  long long ans1 = STD::solve();
  printf("%lld", ans1);
  return 0;
}

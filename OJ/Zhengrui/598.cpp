#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long

using namespace std;

const int kMaxN = 1e6;

int n, m;
int i, j, k;
long long a[kMaxN];
long long b[kMaxN];
long long t[kMaxN];
long long l = 0, r;
long long t1[kMaxN], t2[kMaxN];
long long d[kMaxN];

bool check(long long mid) {
  memset(t1, 0, sizeof(t1));
  memset(t2, 0, sizeof(t2));
  for (int i = 1; i <= m; i++) {
    d[i] = 0;
    for (int j = 0; j < i; j++) {
      if (t1[j] <= t2[j]) {
        t1[j] = upper_bound(a + t1[j] + 1, a + n + 1, a[t1[j]] + mid) - a - 1;
      } else {
        t2[j] = upper_bound(b + t2[j] + 1, b + n + 1, b[t2[j]] + mid) - b - 1;
      }
      d[i] = max(d[i], min(t1[j], t2[j]));
    }
    d[i] = max(d[i], (long long)(upper_bound(t + d[i - 1] + 1, t + 1 + n, t[d[i - 1]] + mid) - t - 1));
    t1[i] = t2[i] = d[i];
  }
  return d[m] == n;
}

signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    b[i] += b[i - 1];
    t[i] = a[i] + b[i];
  }
  long long ans = 0;
  r += a[n] + b[n];
  for (int i = 1; i <= 100; i++) {
    long long mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}

#include <iostream>
#include <cstdio>

using namespace std;

const int kMaxN = 1e6;

int n;
int x[kMaxN], y[kMaxN], s[kMaxN];

bool check(double ans) {
  long double time = 0;
  for (int i = 1; i <= n; i++) {
    time += s[i] / ans;
    if (time > y[i]) return false;
    time = max(time, (long double)x[i]);
  }
  return true;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i] >> s[i];
  }
  long double l = 0, r = 1e18;
  long double ans = 0;
  while (r - l >= 1e-6) {
    long double mid = (l + r) / 2.0;
    if (check(mid)) {
      r = mid;
      ans = mid;
    } else {
      l = mid;
    }
  }
  printf("%.2Lf", ans);
  return 0;
}

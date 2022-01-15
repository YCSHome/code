#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int n;
int p[MAXN], t[MAXN];
int a[MAXN];

int solve(int *p, int *t) {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = p[i] - t[i];
  }
  for (int i = 1; i <= n; i++) {
    ans += (a[i] > a[i - 1]) * (a[i] - a[i - 1]);
  }
  return ans;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  cout << max(solve(p, t), solve(t, p));
  return 0;
}

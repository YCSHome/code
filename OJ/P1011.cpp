#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int a, n, m, x;
int f1[MAXN];
int f2[MAXN];

int main() {
  cin >> a >> n >> m >> x;
  f1[2] = 1;
  f1[3] = 2;
  for (int i = 4; i < n; i++) {
    f1[i] = f1[i - 1] + f1[i - 2] - 1;
    f2[i] = f2[i - 1] + f2[i - 2] + 1;
  }
  int temp = (m - a * f1[n - 1]) / f2[n - 1];
  cout << a * f1[x] + temp * f2[x];
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int n, k, a[MAXN], father[MAXN];

map<int, int> mp;

int solve(int u) {
  for (int v = father[u]; v; v = father[v]) {
    if (__gcd(a[u], a[v]) > 1) {
      return v;
    }
  }
  return -1;
}

int main() {
  int temp = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    father[y] = x;
  }
  while (k--) {
    int op, u, value;
    cin >> op >> u;
    if (op == 1) {
      cout << solve(u) << endl;
    } else {
      cin >> value;
      a[u] = value;
    }
  }
  return 0;
}

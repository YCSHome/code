#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

struct node {
  int x, y;
}a[MAXN];

int n;
int s = 0, ans = INT_MAX;

int len(int x, int y) {
  return abs(a[x].x - a[y].x) + abs(a[x].y - a[y].y);
}

int main() {
  freopen("marathon.in", "r", stdin);
  freopen("marathon.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
    if (i != 1) s += len(i - 1, i);
  }
  for (int i = 2; i < n; i++) {
    int temp = len(i - 1, i) + len(i, i + 1) - len(i - 1, i + 1);
    ans = min(ans, s - temp);
  }
  cout << ans << endl;
  return 0;
}

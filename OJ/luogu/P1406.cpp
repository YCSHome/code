#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

const int kMaxN = 1e6;

int n;
int m;
int a[kMaxN];
int ans[10][10];
bool use[kMaxN];
int t = 0;

void dfs(int x, int y) {
  if (y > n) { x++, y = 1; }
  if (x > n) {
    cout << t << endl;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cout << ans[i][j] << " ";
      }
      cout << endl;
    }
    exit(0);
  }
  for (int i = 1; i <= m; i++) {
    if (use[i]) continue;
    if (y == n) {
      int temp = a[i];
      for (int j = 1; j < n; j++) {
        temp += ans[x][j];
      }
      if (temp != t) continue;
    }
    if (x == n) {
      int temp = a[i];
      for (int j = 1; j < n; j++) {
        temp += ans[j][y];
      }
      if (temp != t) continue;
    }
    if (x == n && y == 1) {
      int temp = a[i];
      for (int j = 1; j < n; j++) {
        temp += ans[j][n - j + 1];
      }
      if (temp != t) continue;
    }
    if (x == n && y == n) {
      int temp = a[i];
      for (int j = 1; j < n; j++) {
        temp += ans[j][j];
      }
      if (temp != t) continue;
    }
    use[i] = true;
    ans[x][y] = a[i];
    dfs(x, y + 1);
    use[i] = false;
  }
}

signed main() {
  cin >> n;
  m = n * n;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    t += a[i];
  }
  sort(a + 1, a + 1 + m);
  t /= n;
  dfs(1, 1);
  return 0;
}

#include <iostream>

using namespace std;

const int kMaxN = 200;

int n, m;
int a[kMaxN][kMaxN];
int dp[kMaxN][kMaxN];

int get(int x1, int y1, int x2, int y2) {
  return a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1];
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      a[i][j] += a[i - 1][j];
      a[i][j] += a[i][j - 1];
      a[i][j] -= a[i - 1][j - 1];
    }
  }
  for (int len = max(n, m); len >= 1; len--) {
    for (int x1 = 1, x2 = len + x1 - 1; x2 <= n; x1++, x2++) {
      for (int y1 = 1, y2 = len + y1 - 1; y2 <= m; y1++, y2++) {
        if (get(x1, y1, x2, y2) == len * len) {
          cout << len << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}

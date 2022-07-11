#include <iostream>
#include <cmath>

using namespace std;

const int kMaxN = 1e6;

int a[kMaxN];
int ans[1145][1145];
int n, m;

int main() {
  cin >> n >> m;
  int BlockSize = sqrt(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 1; j <= BlockSize; j++) {
      ans[j][i % j] += a[i];
    }
  }
  for (int i = 1; i <= m; i++) {
    int x, y; char ch;
    cin >> ch >> x >> y;
    if (ch == 'A') {
      int t = 0;
      if (x <= BlockSize) {
        t = ans[x][y];
      } else {
        for (int i = y; i <= n; i += x) {
          t += a[i];
        }
      }
      cout << t << endl;
    } else {
      for (int i = 1; i <= BlockSize; i++) {
        ans[i][x % i] += y - a[x];
      }
      a[x] = y;
    }
  }
  return 0;
}

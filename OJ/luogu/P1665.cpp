#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int kMaxN = 1100;
const int P = 100;

int ans = 0;
int n;
int x[kMaxN], y[kMaxN];
bool has[kMaxN][kMaxN];

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    x[i] += P, y[i] += P;
    x[i] <<= 1;
    y[i] <<= 1;
    has[x[i]][y[i]] = true;
  }
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int midx = (x[i] + x[j]) >> 1;
      int midy = (y[i] + y[j]) >> 1;
      int x1 = midx - (midy - y[i]), y1 = midy + (midx - x[i]);
      int x2 = midx + (midy - y[i]), y2 = midy - (midx - x[i]);
      if (x1 < 1 || x2 < 1 || y1 < 1 || y2 < 1) continue;
      ans += has[x1][y1] && has[x2][y2];
    }
  }
  cout << (ans / 2);
  return 0;
}

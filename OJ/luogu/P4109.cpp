#include <iostream>
#include <cmath>

using namespace std;

const int INF = 1e9;

int n;
int inf = INF;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int l, r, ans = 0;
    cin >> l >> r;
    while (l <= r) {
      int x = l, temp = 0;
      while (x % 10 == 0) {
        x /= 10;
        temp++;
      }
      int y = x, temp2 = 0;
      while (y) {
        y /= 10;
        temp2++;
      }
      int t = 0;
      t = 2 * temp2 - (x % 10 == 5);
      if (inf > t) {
        inf = t;
        ans = l;
      }
      l += pow(10, temp);
    }
    cout << ans << endl;
    inf = INF;
  }
  return 0;
}

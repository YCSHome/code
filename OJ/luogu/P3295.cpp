#include <iostream>
#include <cmath>
#define int long long

using namespace std;

const int kMaxN = 1e6;
const int MOD = 1e9 + 7;

int n, m;
int father[kMaxN][30];

int findFather(int x, int y) {
  if (father[x][y] == x) return x;
  return father[x][y] = findFather(father[x][y], y);
}

void merge(int x, int y, int k) {
  int a = findFather(x, k);
  int b = findFather(y, k);
  if (a == b) return;
  father[a][k] = b;
}

signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 30; j++) {
      father[i][j] = i;
    }
  }
  for (int i = 1; i <= m; i++) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    for (int k = log2(n) + 1; k >= 0; k--) { // 这里优化只有一点点，没啥用
      if (l1 + (1 << k) - 1 <= r1) {
        merge(l1, l2, k);
        l1 += (1 << k);
        l2 += (1 << k);
      }
    }
  }
  for (int k = log2(n) + 1; k >= 1; k--) {
    for (int i = 1; i <= n - (1 << k) + 1; i++) {
      int p = findFather(i, k);
      merge(i, p, k - 1);
      merge(i + (1 << (k - 1)), p + (1 << (k - 1)), k - 1);
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (father[i][0] == i) {
      if (ans == 0) ans = 9;
      else ans = ans * 10;
      ans %= MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
/*
9
90
900
9000
90000
900000
9000000
90000000
900000000
999999944
999999377
999993707
999937007
999370007
993700007
937000007
370000007
700000049
441
4410
44100
441000
4410000
44100000
441000000
409999972
99999692
999996920
999969137
999969137
 */

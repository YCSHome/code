#include <iostream>
#include <map>

using namespace std;

const int kMaxN = 1e6 + 1000;

int n, q;
map<int, int> m[kMaxN];

int main() {
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    int opt, x, y;
    cin >> opt >> x >> y;
    if (opt == 1) {
      int k;
      cin >> k;
      m[x][y] = k;
    } else {
      cout << m[x][y] << endl;
    }
  }
  return 0;
}

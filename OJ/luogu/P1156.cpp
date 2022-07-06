#include <iostream>
#include <algorithm>

using namespace std;

const int kMaxN = 1e4;

struct fake {
  int t, f, h;
  bool operator<(const fake& cmp) const {
    return t < cmp.t;
  }
}f[kMaxN];

int D, G;
bool ableTo[5001][101][3001];
int life[3000];
// i 件物品，高度，生命值为j

int main() {
  cin >> D >> G;
  for (int i = 1; i <= G; i++) {
    cin >> f[i].t >> f[i].f >> f[i].h;
  }
  sort(f + 1, f + 1 + G);
  life[0] = 10;
  for (int i = 1; i <= G; i++) {
    for (int j = D; j >= 0; j--) {
      if (life[j] >= f[i].t) {
        if (j + f[i].h >= D) {
          cout << f[i].t << endl;
          return 0;
        }
        life[j + f[i].h] = max(life[j + f[i].h], life[j]);
        life[j] += f[i].f;
      }
    }
  }
  cout << life[0] << endl;
  return 0;
}

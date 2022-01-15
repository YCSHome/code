#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;

class BitTree {
private:
  int a[MAXN];
  static int lowbit(int x) {
    return x & -x;
  }

public:
  void add(int x, int y) {
    for (; x < MAXN; x += lowbit(x)) {
      a[x] += y;
    }
  }
};

struct que {
  int x, y;
}que[MAXN];

int n, m;
int a[MAXN];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> que[i].x >> que[i].y;
  }
  return 0;
}

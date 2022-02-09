#include <bits/stdc++.h>

#include <functional>

using namespace std;

const int MAXN = 1e6;
const int MAXLOG = 32;

template <class type_, class cmp_>
struct Max {
  cmp_ cmper;
  type_ operator()(const type_& a, const type_& b) {
    return cmper(a, b) ? a : b;
  }
};

template <class cmp>
class ST {
private:
  int LOG[MAXN];
  int (*a)[MAXN];
  cmp cmper;

public:
  void build(int a[][MAXN], int n) {
    this->a = a;
    LOG[1] = 0;
    LOG[2] = 1;
    for (int i = 3; i < MAXN; i++) {
      LOG[i] = LOG[i / 2] + 1;
    }
    for (int j = 1; j < MAXLOG - 1; j++) {
      for (int i = 1; i <= n; i++) {
        if (i + (1 << j) - 1 <= n) {
          a[j][i] = cmper(a[j - 1][i], a[j - 1][i + (1 << (j - 1))]);
        }
      }
    }
  }

  int get(int l, int r) {
    int k = LOG[(r - l + 1)];
    return cmper(a[k][l], a[k][r - (1 << k) + 1]);
  }

  ST() {}
  ST(int a[][MAXN], int n) { build(a, n); }
};

int a[2][MAXLOG][MAXN];
int n, m;
ST<Max<int, greater<int>>> high;
ST<Max<int, less<int>>> low;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[0][0][i];
    a[1][0][i] = a[0][0][i];
  }
  high.build(a[0], n);
  low.build(a[1], n);
  while (m--) {
    int l, r;
    cin >> l >> r;
    cout << high.get(l, r) - low.get(l, r) << endl;
  }
  return 0;
}

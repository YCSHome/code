#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
const int MAXLOG = 32;

class ST {
private:
  static int LOG[MAXN];
  int (*a)[MAXN];
public:
  void build(int a[][MAXN], int n) {
    this->a = a;
    for (int j = 1; j < MAXLOG - 1; j++) {
      for (int i = 1; i <= n; i++) {
        if (i + (1 << j) - 1 <= n) {
          a[j][i] = min(a[j - 1][i], a[j - 1][i + (1 << (j - 1))]);
        }
      }
    }
  }

  int get(int l, int r) {
    int k = LOG[(r - l + 1)];
    return min(a[k][l], a[k][r - (1 << k) + 1]);
  }

  ST() {
    if (LOG[2] == 1) return;
    LOG[1] = 0;
    LOG[2] = 1;
    for (int i = 3; i < MAXN; i++) {
      LOG[i] = LOG[i / 2] + 1;
    }
  }
};

int ST::LOG[MAXN];
int a[MAXLOG][MAXN];
int n, m;
ST st;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[0][i];
  }
  st.build(a, n);
  for (int l = 1, r = 1 + m - 1; r <= n; l++, r++) {
    cout << st.get(l, r) << endl;
  }
  return 0;
} 

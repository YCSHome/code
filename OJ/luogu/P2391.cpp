#include <iostream>

using namespace std;

const int kMaxN = 2e6;

int n, m, p, q;
int a[kMaxN];
int father[kMaxN];

int find(int x) {
  return x == father[x] ? x : father[x] = find(father[x]);
}

int main() {
  for (int i = 1; i < kMaxN; i++) { father[i] = i; }
  cin >> n >> m >> p >> q;
  for (int i = m; i >= 1; i--) {
    long long x = (i * p + q) % n + 1;
    long long y = (i * q + p) % n + 1;
    if (x > y) { swap(x, y); }
    x = find(x);
    while (x <= y) {
      father[x] = x + 1;
      a[x] = i;
      x = find(x);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << endl;
  }
  return 0;
}

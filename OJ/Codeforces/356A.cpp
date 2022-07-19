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
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    for (int i = find(l); i <= r; i = find(i + 1)) {
      if (i != x) {
        a[i] = x;
        father[i] = i + 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}

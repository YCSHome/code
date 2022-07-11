#include <iostream>
#include <algorithm>

using namespace std;

const int kMaxN = 1e6;

struct plan {
  int x, y, t;
  bool operator<(const plan& cmp) const {
    return t < cmp.t;
  }
}a[kMaxN];

int n, m;
int father[kMaxN];
int Size[kMaxN];

int find(int x) {
  return x == father[x] ? x : find(father[x]);
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) father[i] = i, Size[i] = 1;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].x >> a[i].y >> a[i].t;
    if (a[i].x > a[i].y) swap(a[i].x, a[i].y);
  }
  sort(a + 1, a + 1 + m);
  for (int i = 1; i <= m; i++) {
    int a_ = find(a[i].x), b = find(a[i].y);
    if (a_ == b) continue;
    Size[a_] += Size[b];
    father[b] = a_;
    if (Size[a_] == n || Size[b] == n || Size[1] == n) {
      cout << a[i].t << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}

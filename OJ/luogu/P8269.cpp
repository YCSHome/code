#include <bits/stdc++.h>

using namespace std;

const long long kMaxN = 1e6;

struct edge {
  long long x, y, v;
  bool operator<(const edge& b) const {
    return v > b.v;
  }
} e[kMaxN];

long long n;
long long a[kMaxN];
long long v[kMaxN];
long long father[kMaxN];
long long dis[kMaxN];

long long find(int x) {
  if (father[x] == x) {
    return x;
  }
  return father[x] = find(father[x]);
}

void Unionn(long long x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  father[x] = y;
}

int main() {
  for (long long i = 1; i < kMaxN; i++) father[i] = i;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> e[i].y >> e[i].v;
    e[i].x = i;
  }
  long long ans = 0;
  sort(e + 1, e + 1 + n);
  for (long long i = 1; i <= n; i++) {
    if (find(e[i].x) != find(e[i].y)) {
      Unionn(e[i].x, e[i].y);
      ans += e[i].v;
    }
  }
  cout << ans << endl;
  return 0;
}

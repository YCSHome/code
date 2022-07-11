#include <iostream>
#include <algorithm>

using namespace std;

const int kMaxN = 2e6;

struct edge {
  int x, y, t;
  bool operator<(const edge& cmp) const {
    return t > cmp.t;
  }
}e[kMaxN];

struct node {
  int k, v, ID;
  bool operator<(const node& cmp) const {
    return k > cmp.k;
  }
}a[kMaxN];

int father[kMaxN];
int size[kMaxN];
int ans[kMaxN];

int find(int x) {
  if (x == father[x]) {
    return x;
  }
  return father[x] = find(father[x]);
}

void Union(int x, int y) {
  x = find(x), y = find(y);
  if (x != y) {
    father[x] = y;
    size[y] += size[x];
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    father[i] = i;
    size[i] = 1;
  }
  for (int i = 1; i <= n - 1; i++) {
    cin >> e[i].x >> e[i].y >> e[i].t;
  }
  for (int i = 1; i <= q; i++) {
    cin >> a[i].k >> a[i].v;
    a[i].ID = i;
  }
  sort(e + 1, e + 1 + n);
  sort(a + 1, a + 1 + q);
  int j = 1;
  for (int i = 1; i <= q; i++) {
    while (j < n && e[j].t >= a[i].k) {
      Union(e[j].x, e[j].y);
      j++;
   }
    ans[a[i].ID] = size[find(a[i].v)];
  }
  for (int i = 1; i <= q; i++) {
    cout << ans[i] - 1 << endl;
  }
  return 0;
}

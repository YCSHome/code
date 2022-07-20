#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int kMaxN = 5e5 + 10;
const int kMaxSize = 710;

int blockSize = 0;
int dis[kMaxSize][kMaxSize];

int n, q, tot = 0;
int a[kMaxN];
int b[kMaxN];
int number[kMaxN];
int p[kMaxN];
vector<int> v[kMaxN];

inline int getBlock(int x) {
  return (x - 1) / blockSize + 1;
}

inline int getLeft(int block) {
  return (block - 1) * blockSize + 1;
}

inline int getRight(int block) {
  return min(block * blockSize, n);
}

inline int get(int x, int y) {
  if (getBlock(x) == getBlock(y)) {
    for (int i = x; i <= y; i++) {
      number[a[i]] = 0;
    }
    int ans = 0;
    for (int i = x; i <= y; i++) {
      number[a[i]]++;
      ans = max(ans, number[a[i]]);
    }
    return ans;
  }
  int bx = getBlock(x), by = getBlock(y);
  int ans = 0;
  if (bx + 1 <= by - 1) {
    ans = dis[bx + 1][by - 1];
  }
  for (int i = x; i <= getRight(bx); i++) {
    int p = ::p[i];
    int v = p + ans;
    while (v < ::v[a[i]].size() && ::v[a[i]][v] <= y) {
      v++, ans++;
    }
  }
  for (int i = getLeft(by); i <= y; i++) {
    int p = ::p[i];
    int v = p - ans;
    while (v >= 0 && ::v[a[i]][v] >= x) {
      v--, ans++;
    }
  }
  return ans;
}

signed main() {
  scanf("%d%d", &n, &q);
  blockSize = 800;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  tot = unique(b + 1, b + 1 + n) - b - 1;
  for (int i = 1; i <= n; i++) { a[i] = lower_bound(b + 1, b + 1 + tot, a[i]) - b; }
  for (int i = 1; i <= n; i++) { v[a[i]].emplace_back(i); p[i] = v[a[i]].size() - 1; }
  for (int i = 1; i <= getBlock(n); i++) {
    memset(number, 0, sizeof(number));
    for (int j = i; j <= getBlock(n); j++) {
      dis[i][j] = dis[i][j - 1];
      for (int k = getLeft(j); k <= getRight(j); k++) {
        number[a[k]]++;
        dis[i][j] = max(dis[i][j], number[a[k]]);
      }
    }
  }
  int lastans = 0;
  for (int i = 1; i <= q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    l ^= lastans;
    r ^= lastans;
    printf("%d\n", lastans = get(l, r));
  }
  return 0;
}

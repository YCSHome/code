#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

const int kMaxN = 1e5 + 10;
const int kMaxSize = 500;

int blockSize = 0;
long long numberCount[kMaxSize][kMaxN];
long long dis[kMaxSize][kMaxSize];

int n, q, tot = 0;
int a[kMaxN];
int b[kMaxN];
long long number[kMaxN];

int getBlock(int x) {
  return (x - 1) / blockSize + 1;
}

int getLeft(int block) {
  return (block - 1) * blockSize + 1;
}

int getRight(int block) {
  return min(block * blockSize, n);
}

long long get(int x, int y) {
  if (getBlock(x) == getBlock(y) || getBlock(x) + 1 == getBlock(y)) {
    memset(number, 0, sizeof(number));
    long long ans = 0;
    for (int i = x; i <= y; i++) {
      number[a[i]]++;
      ans = max(ans, number[a[i]] * b[a[i]]);
    }
    return ans;
  }
  int bx = getBlock(x), by = getBlock(y);
  long long ans = 0;
  if (bx + 1 <= by - 1) {
    ans = dis[bx + 1][by - 1];
  }
  memset(number, 0, sizeof(number));
  for (int i = x; i <= getRight(bx); i++) {
    number[a[i]]++;
    ans = max(ans, ((numberCount[by - 1][a[i]] - numberCount[bx][a[i]]) + number[a[i]]) * b[a[i]]);
  }
  for (int i = getLeft(by); i <= y; i++) {
    number[a[i]]++;
    ans = max(ans, ((numberCount[by - 1][a[i]] - numberCount[bx][a[i]]) + number[a[i]]) * b[a[i]]);
  }
  return ans;
}

signed main() {
  scanf("%d%d", &n, &q);
  blockSize = sqrt(n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  tot = unique(b + 1, b + 1 + n) - b - 1;
  for (int i = 1; i <= n; i++) { a[i] = lower_bound(b + 1, b + 1 + tot, a[i]) - b; }
  for (int i = 1; i <= n; i++) { numberCount[getBlock(i)][a[i]]++; }
  for (int i = 1; i <= getBlock(n); i++) {
    for (int j = 1; j <= tot; j++) {
      numberCount[i][j] += numberCount[i - 1][j];
    }
  }
  for (int i = 1; i <= getBlock(n); i++) {
    memset(number, 0, sizeof(number));
    long long max = 0;
    for (int j = getLeft(i); j <= n; j++) {
      int to = getBlock(j);
      number[a[j]]++;
      max = ::max(max, (long long)number[a[j]] * b[a[j]]);
      dis[i][getBlock(j)] = max;
    }
  }
  for (int i = 1; i <= q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%lld\n", get(l, r));
  }
  return 0;
}

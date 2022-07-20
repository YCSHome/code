#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <limits>
#define int int

using namespace std;

const int kMaxN = 3e5 + 10;
const int kMaxSize = 500;

int blockSize = 0;
int numberCount[kMaxSize][kMaxN];
int dis[kMaxSize][kMaxSize];

int n, q, tot = 0;
int a[kMaxN];
int b[kMaxN];
int number[kMaxN];

int getBlock(int x) {
  return (x - 1) / blockSize + 1;
}

int getLeft(int block) {
  return (block - 1) * blockSize + 1;
}

int getRight(int block) {
  return min(block * blockSize, n);
}

inline int get(int bx, int by, int x) {
  return numberCount[by - 1][x] - numberCount[bx][x] + number[x];
}

int get(int x, int y) {
  if (getBlock(x) == getBlock(y) || getBlock(x) + 1 == getBlock(y)) {
    int ans = 0;
    for (int i = x; i <= y; i++) {
      number[a[i]]++;
      if (number[a[i]] > number[ans]) {
        ans = a[i];
      }
      if (number[a[i]] == number[ans] && a[i] < ans) {
        ans = a[i];
      }
    }
    for (int i = x; i <= y; i++) { number[a[i]] = 0; }
    return b[ans];
  }
  int bx = getBlock(x), by = getBlock(y);
  int ans = 0;
  if (bx + 1 <= by - 1) {
    ans = dis[bx + 1][by - 1];
  }
  for (int i = x; i <= getRight(bx); i++) {
    number[a[i]]++;
    int t = get(bx, by, a[i]);
    int aa = get(bx, by, ans);
    if (t > aa) {
      ans = a[i];
    } 
    if (t == aa && ans > a[i]) {
      ans = a[i];
    }
  }
  for (int i = getLeft(by); i <= y; i++) {
    number[a[i]]++;
    int t = get(bx, by, a[i]);
    int aa = get(bx, by, ans);
    if (t > aa) {
      ans = a[i];
    } 
    if (t == aa && ans > a[i]) {
      ans = a[i];
    }
  }
  for (int i = getLeft(by); i <= y; i++) { number[a[i]] = 0; }
  for (int i = x; i <= getRight(bx); i++) { number[a[i]] = 0; }
  return b[ans];
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
    int max = 0;
    for (int j = getLeft(i); j <= n; j++) {
      int to = getBlock(j);
      number[a[j]]++;
      if (number[max] < number[a[j]]) {
        max = a[j];
      }
      if (number[max] == number[a[j]] && a[j] < max) {
        max = a[j];
      }
      dis[i][getBlock(j)] = max;
    }
    memset(number, 0, sizeof(number));
  }
  int lastans = 0;
  for (int i = 1; i <= q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    l = ((l + lastans - 1) % n) + 1;
    r = ((r + lastans - 1) % n) + 1;
    if (l > r) swap(l, r);
    printf("%d\n", lastans = get(l, r));
  }
  return 0;
}

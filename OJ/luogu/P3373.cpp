#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 1e5;

int P;
long long a[MAXN << 2];

struct node {
  long long v, mul, add;
} tree[MAXN << 2];

int left_son(int p) { return p * 2; }

int right_son(int p) { return p * 2 + 1; }

void build(int p, int l, int r) {
  tree[p].mul = 1;
  tree[p].add = 0;
  if (l == r) {
    tree[p].v = a[l];
  } else {
    int m = (l + r) / 2;
    build(left_son(p), l, m);
    build(right_son(p), m + 1, r);
    tree[p].v = tree[left_son(p)].v + tree[right_son(p)].v;
  }
  tree[p].v %= P;
  return;
}

void pushdown(int p, int l, int r) {
  int m = (l + r) / 2;
  tree[left_son(p)].v =
      (tree[left_son(p)].v * tree[p].mul + tree[p].add * (m - l + 1)) % P;
  tree[right_son(p)].v =
      (tree[right_son(p)].v * tree[p].mul + tree[p].add * (r - m)) % P;
  tree[left_son(p)].mul = (tree[left_son(p)].mul * tree[p].mul) % P;
  tree[right_son(p)].mul = (tree[right_son(p)].mul * tree[p].mul) % P;
  tree[left_son(p)].add =
      (tree[left_son(p)].add * tree[p].mul + tree[p].add) % P;
  tree[right_son(p)].add =
      (tree[right_son(p)].add * tree[p].mul + tree[p].add) % P;
  tree[p].mul = 1;
  tree[p].add = 0;
  return;
}

void update1(int p, int L, int R, int l, int r, long long k) {
  if (r < L || R < l) {
    return;
  }
  if (l <= L && R <= r) {
    tree[p].v = (tree[p].v * k) % P;
    tree[p].mul = (tree[p].mul * k) % P;
    tree[p].add = (tree[p].add * k) % P;
    return;
  }
  pushdown(p, L, R);
  int m = (L + R) / 2;
  update1(left_son(p), L, m, l, r, k);
  update1(right_son(p), m + 1, R, l, r, k);
  tree[p].v = (tree[left_son(p)].v + tree[right_son(p)].v) % P;
  return;
}

void update2(int p, int L, int R, int l, int r, long long k) {
  if (r < L || R < l) {
    return;
  }
  if (l <= L && R <= r) {
    tree[p].add = (tree[p].add + k) % P;
    tree[p].v = (tree[p].v + k * (R - L + 1)) % P;
    return;
  }
  pushdown(p, L, R);
  int m = (L + R) / 2;
  update2(left_son(p), L, m, l, r, k);
  update2(right_son(p), m + 1, R, l, r, k);
  tree[p].v = (tree[left_son(p)].v + tree[right_son(p)].v) % P;
  return;
}

long long get(int p, int L, int R, int l, int r) {
  if (r < L || R < l) {
    return 0;
  }
  if (l <= L && R <= r) {
    return tree[p].v;
  }
  pushdown(p, L, R);
  int m = (L + R) / 2;
  return (get(left_son(p), L, m, l, r) + get(right_son(p), m + 1, R, l, r)) % P;
}

int main() {
  memset(tree, 0, sizeof(tree));
  int n, m;
  cin >> n >> P;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  cin >> m;
  while (m--) {
    int opt;
    cin >> opt;
    int x, y;
    long long k;
    if (opt == 1) {
      cin >> x >> y >> k;
      update1(1, 1, n, x, y, k);
    } else if (opt == 2) {
      cin >> x >> y >> k;
      update2(1, 1, n, x, y, k);
    } else {
      cin >> x >> y;
      cout << get(1, 1, n, x, y) << endl;
    }
  }
  return 0;
}

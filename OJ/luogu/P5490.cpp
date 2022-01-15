#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

int n, cnt = 0;
long long X[MAXN << 1];

struct line {
  long long l, r, h;
  int mark;
  bool operator<(const line &cmp) const { return h < cmp.h; }
} line[MAXN << 1];

struct node {
  int l, r, sum;
  long long len;
} tree[MAXN << 2];

int left_son(int p) {
  return p << 1;
}

int right_son(int p) {
  return p << 1 | 1;
}

void build(int p, int l, int r) {
  tree[p].l = l, tree[p].r = r;
  tree[p].len = 0;
  tree[p].sum = 0;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(left_son(p), l, mid);
  build(right_son(p), mid + 1, r);
  return;
}

void update(int p) {
  int l = tree[p].l, r = tree[p].r;
  if (tree[p].sum) {
    tree[p].len = X[r + 1] - X[l];
  } else {
    tree[p].len = tree[left_son(p)].len + tree[right_son(p)].len;
  }
}

void change(int p, long long L, long long R, int c) {
  int l = tree[p].l, r = tree[p].r;
  if (X[r + 1] <= L || R <= X[l]) return;
  if (L <= X[l] && X[r + 1] <= R) {
    tree[p].sum += c;
    update(p);
    return;
  }
  change(left_son(p), L, R, c);
  change(right_son(p), L, R, c);
  update(p);
}

int main() {
  long long x1, y1, x2, y2;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    X[2 * i - 1] = x1, X[2 * i] = x2;
    line[2 * i - 1] = {x1, x2, y1, 1};
    line[2 * i] = {x1, x2, y2, -1};
  }
  n *= 2;
  sort(line + 1, line + n + 1);
  sort(X + 1, X + n + 1);
  int tot = unique(X + 1, X + n + 1) - X - 1;
  build(1, 1, tot - 1);
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    change(1, line[i].l, line[i].r, line[i].mark);
    ans += tree[1].len * (line[i + 1].h - line[i].h);
  }
  cout << ans;
  return 0;
}

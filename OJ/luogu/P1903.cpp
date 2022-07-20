#include <exception>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int kMaxN = 2e6 + 100;

int blockSize = 0;

int getBlock(int x) {
  return (x - 1) / blockSize + 1;
}

struct node {
  int l, r;
  int time = 0, id = 0;
  bool operator<(const node& cmp) const {
    if (getBlock(l) != getBlock(cmp.l)) {
      return l < cmp.l;
    }
    if (getBlock(r) != getBlock(cmp.r)) {
      return r < cmp.r;
    }
    return time < cmp.time;
  }
}b[kMaxN];

struct plan {
  int time = 0;
  int pos, value;
}c[kMaxN];

int n, m;
int a[kMaxN];
int cnt[kMaxN];
int ans = 0;
int qAns[kMaxN];

void add(int x) {
  cnt[x]++;
  if (cnt[x] == 1) ans++;
}

void del(int x) {
  cnt[x]--;
  if (cnt[x] == 0) ans--;
}

void work(int p, int l, int r) {
  if (c[p].pos <= r && l <= c[p].pos) {
    del(a[c[p].pos]);
    add(c[p].value);
  }
  swap(a[c[p].pos], c[p].value);
}

int main() {
  scanf("%d%d", &n, &m);
  blockSize = pow(n, 0.666666666);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int tot = 0, x, y;
  int lastTime = 0;
  for (int i = 1; i <= m; i++) {
    char ch[10];
    scanf("%s", ch);
    scanf("%d%d", &x, &y);
    if (ch[0] == 'Q') {
      b[++tot].l = x;
      b[tot].r= y;
      b[tot].time = lastTime;
      b[tot].id = tot;
    } else {
      c[++lastTime].pos = x;
      c[lastTime].value = y;
    }
  }
  sort(b + 1, b + 1 + tot);
  int l = 1, r = 0, time = 0;
  for (int i = 1; i <= tot; i++) {
    while (r < b[i].r) add(a[++r]);
    while (l > b[i].l) add(a[--l]);
    while (r > b[i].r) del(a[r--]);
    while (l < b[i].l) del(a[l++]);
    while (time < b[i].time) work(++time, l, r);
    while (time > b[i].time) work(time--, l, r);
    qAns[b[i].id] = ans;
  }
  for (int i = 1; i <= tot; i++) {
    printf("%d\n", qAns[i]);
  }
  return 0;
}

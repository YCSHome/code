#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

struct que {
  int l, r, belong, id;
  bool operator<(const que& cmp) const {
    if (belong == cmp.belong) {
      return belong & 1 ? r < cmp.r : r > cmp.r;
    } else {
      return l < cmp.l;
    }
  }
}q[MAXN];

int n, m;
int a[MAXN], ans[MAXN], temp, b[MAXN];
int cnt[MAXN];

void add(int x, int k) {
  if (cnt[x] == 2) {
    temp--;
  }
  cnt[x] += k;
  if (cnt[x] == 2) {
    temp++;
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  {
    sort(b + 1, b + 1 + n);
    int cnt = unique(b + 1, b + 1 + n) - b - 1;
    for (int i = 1; i <= n; i++) {
      a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
    }
  }
  int block = sqrt(n);
  for (int i = 1; i <= m; i++) {
    cin >> q[i].l >> q[i].r;
    q[i].belong = q[i].l / block;
    q[i].id = i;
  }
  sort(q + 1, q + 1 + m);
  int l = 1, r = 0;
  for (int i = 1; i <= m; i++) {
    int ql = q[i].l, qr = q[i].r;
    while (l < ql) add(a[l++], -1);
    while (l > ql) add(a[--l], 1);
    while (r < qr) add(a[++r], 1);
    while (r > qr) add(a[r--], -1);
    ans[q[i].id] = temp;
  }
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}

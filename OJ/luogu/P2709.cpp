#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int BlockSize;

struct node {
  int l, r, id, belong;
  bool operator<(const node& cmp) const {
    if (belong == cmp.belong) {
      return belong & 1 ? r < cmp.r : r > cmp.r;
    } else {
      return belong < cmp.belong;
    }
  }
} que[MAXN];

int n, m, k;
long long a[MAXN];
long long cnt[MAXN];
long long Ans[MAXN];
long long ans = 0;

void add(int x) {
  ans += 2 * cnt[a[x]] + 1;
  cnt[a[x]]++;
}

void del(int x) {
  ans -= 2 * cnt[a[x]] - 1;
  cnt[a[x]]--;
}

int main() {
  cin >> n >> m >> k;
  BlockSize = sqrt(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> que[i].l >> que[i].r;
    que[i].id = i;
    que[i].belong = (que[i].l - 1) / BlockSize;
  }
  sort(que + 1, que + 1 + m);
  int l = 1, r = 0;
  for (int i = 1; i <= m; i++) {
    int ql = que[i].l, qr = que[i].r;
    while (l < ql) del(l++);
    while (l > ql) add(--l);
    while (r < qr) add(++r);
    while (r > qr) del(r--);
    Ans[que[i].id] = ans;
  }
  for (int i = 1; i <= m; i++) {
    cout << Ans[i] << endl;
  }
  return 0;
}

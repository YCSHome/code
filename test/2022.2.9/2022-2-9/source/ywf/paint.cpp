#include <bits/stdc++.h>
using namespace std;
int ans;
int cnt;
int n, m, k;
int a[110000];
bool b[110000];
bool pd[110000];
bool sp[110000];
struct node {
  int u, d, l, r;
} col[110000];
int get(int x, int y) { return (x - 1) * m + y; }
int read() {
  int r = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') {
    c = getchar();
  }
  if (c == '-') {
    f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    r = (r << 3) + (r << 1) + c - '0';
    c = getchar();
  }
  return r * f;
}
void deal(int now) {
  for (int i = col[now].u; i <= col[now].d; i++) {
    for (int j = col[now].l; j <= col[now].r; j++) {
      int x = get(i, j);
      b[x] = 1;
      if (a[x] != now) {
        pd[a[x]] = 0;
        deal(a[x]);
      }
    }
  }
  return;
}
int main() {
  freopen("paint.in", "r", stdin);
  freopen("paint.out", "w", stdout);
  n = read(), m = read(), k = read();
  memset(pd, 1, sizeof(pd));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x = get(i, j);
      a[x] = read();
      if (!sp[a[x]]) {
        cnt++;
        sp[a[x]] = 1;
      }
      if (!col[a[x]].u) {
        col[a[x]].u = i;
      } else {
        col[a[x]].u = min(col[a[x]].u, i);
      }
      if (!col[a[x]].l) {
        col[a[x]].l = j;
      } else {
        col[a[x]].l = min(col[a[x]].l, j);
      }
      col[a[x]].d = max(col[a[x]].d, i);
      col[a[x]].r = max(col[a[x]].r, j);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x = get(i, j);
      if (!pd[a[x]] || b[x] || a[x] == 0) {
        continue;
      }
      deal(a[x]);
    }
  }
  for (int i = 1; i <= k; i++) {
    if (pd[i]) {
      ans++;
    }
  }
  if (cnt == 1) {
    cout << k - 1;
    return 0;
  }
  cout << ans;
  return 0;
}

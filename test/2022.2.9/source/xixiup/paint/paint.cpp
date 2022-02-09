#include <bits/stdc++.h>
using namespace std;
const int maxk = 100100;
int n, m, k;
int maxx[maxk], maxy[maxk], minx[maxk], miny[maxk];
bool pd[maxk];
void read(int &x) {
  char c = getchar();
  x = 0;
  while (c < '0' || c > '9') {
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
}
int main() {
  freopen("paint.in", "r", stdin);
  freopen("paint.out", "w", stdout);
  read(n);
  read(m);
  read(k);
  int a[n + 1][m + 1];
  memset(a, 0, sizeof(a));
  memset(minx, 0x3f, sizeof(minx));
  memset(miny, 0x3f, sizeof(miny));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      read(a[i][j]);
      maxx[a[i][j]] = max(maxx[a[i][j]], i);
      maxy[a[i][j]] = max(maxy[a[i][j]], j);
      minx[a[i][j]] = min(minx[a[i][j]], i);
      miny[a[i][j]] = min(miny[a[i][j]], j);
    }
  }
  int ans = k;
  for (int l = 1; l <= k; l++) {
    for (int i = minx[l]; i <= maxx[l]; i++) {
      for (int j = miny[l]; j <= maxy[l]; j++) {
        if (a[i][j] != 0 && a[i][j] != l && pd[a[i][j]] == 0) {
          pd[a[i][j]] = 1;
          ans--;
        }
      }
    }
  }
  printf("%d", ans);
  return 0;
}
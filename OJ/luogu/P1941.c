#include <stdio.h>
#include <string.h>
#define min(x, y) (x < y ? x : y)

const int kMaxN = 1e6;
const int INF = 0x3f3f3f3f;

int n, m, k, ans = 0;
int x[1000000], y[1000000];
int up[1000000], down[1000000];
int able[11000][1101];
int has[1000000];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  memset(up, 0x3f, sizeof(up));
  memset(down, 0, sizeof(down));
  memset(able, 0x3f, sizeof(able));
  for (int i = 0; i <= m; i++) {
    able[0][i] = 0;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", x + i, y + i);
  }
  for (int i = 1; i <= k; i++) {
    int x, l, p;
    scanf("%d%d%d", &x, &l, &p);
    up[x] = p, down[x] = l;
    has[x] = 1;
  }
  int flag = 0;
  for (int i = 0; i < n; i++) {
    ans += has[i];
    flag = 0;
    for (int j = 0; j <= m; j++) {
      if (able[i][j] != INF) {
        for (int q = 1; j + x[i] * q < x[i] + m; q++) {
          int U = min(j + x[i] * q, m);
          if (U > down[i + 1] && U < up[i + 1]) {
            able[i + 1][U] = min(able[i + 1][U], able[i][j] + q);
            flag = 1;
          }
        }
        int D = j - y[i];
        if (D > down[i + 1] && D < up[i + 1]) {
          able[i + 1][D] = min(able[i + 1][D], able[i][j]);
          flag = 1;
        }
      }
    }
    if (!flag) {
      printf("%d\n%d", 0, ans);
      return 0;
    }
  }
  int ans = INF;
  for (int i = 1; i <= m; i++) {
    ans = min(ans, able[n][i]);
  }
  printf("%d\n%d", 1, ans);
  return 0;
}
/*
   ||
   |
   ||
   |
   ||
   */

#include <stdio.h>
#include <string.h>
#include <limits.h>

int n;
char ch;
int a[5001], c[5001];

int main() {
  scanf("%d", &n);
  getchar();
  for (int i = 1; i <= n; i++) {
    ch = getchar();
    getchar();
    a[i] = (ch == 'F');
  }
  int ans = INT_MAX, ansk = 0;
  for (int k = 1; k <= n; k++) {
    int flag = 0;
    memset(c, 0, sizeof(c));
    int m = 0;
    for (int i = 1, j = k; i <= n; i++, j++) {
      flag ^= c[i];
      if ((a[i] ^ flag) == 0) {
        if (j > n) {
          m = INT_MAX;
          break;
        }
        m++;
        flag ^= 1;
        c[j + 1] ^= 1;
      }
    }
    if (ans > m) {
      ans = m;
      ansk = k;
    }
  }
  printf("%d %d", ansk, ans);
  return 0;
}

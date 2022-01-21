#include <stdio.h>
#define max(x, y) (x > y ? x : y)

char ch;
char str[2000];
int n, m, q, l = 1, r = 0, ans, temp;

int main() {
  scanf("%d%s%d", &n, str + 1, &q);
  while (q--) {
    l = 1, r = 0, ans = 0, temp = 0;
    scanf("%d %c", &m, &ch);
    for (; l <= n; temp -= (str[l++] != ch)) {
      for (; temp <= m && r <= n; temp += (str[++r] != ch)) {
      }
      ans = max(ans, r - l);
    }
    printf("%d", ans);
    putchar('\n');
  }
  return 0;
}

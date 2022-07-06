#include <stdio.h>

int a[100100];
int n;
int t, ans;

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  ans = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i + 1]) {
      ans++, i++;
    }
  }
  printf("%d\n", ans);
}

int main() {
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}

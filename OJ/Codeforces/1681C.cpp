#include <iostream>
#include <vector>

using namespace std;

const int kMaxN = 1e6;

int n;
int a[kMaxN], b[kMaxN];
int cnt;
int l[kMaxN], r[kMaxN];

void solve() {
  cnt = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", b + i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (a[i] == a[j] ? b[i] < b[j] : a[i] < a[j]) {
        swap(a[i], a[j]);
        swap(b[i], b[j]);
        l[++cnt] = i, r[cnt] = j;
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    if (b[i] < b[i - 1]) {
      printf("-1\n");
      return;
    }
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++) {
    printf("%d %d\n", l[i], r[i]);
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

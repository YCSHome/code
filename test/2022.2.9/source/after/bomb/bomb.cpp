#include <bits/stdc++.h>
using namespace std;
#define Maxn 1000010
int n, x[Maxn], l[Maxn], r[Maxn], ans;
inline int read() {
  int num = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    num = (num << 3) + (num << 1) + ch - '0';
    ch = getchar();
  }
  return num * f;
}
int main() {
  freopen("bomb.in", "r", stdin);
  freopen("bomb.out", "w", stdout);
  n = read();
  for (int i = 1; i <= n; ++i) {
    x[i] = read();
  }
  sort(x + 1, x + 1 + n);
  n = unique(x + 1, x + 1 + n) - x - 1;
  int now = 1;
  for (int i = 2; i <= n; ++i) {
    while (now + 1 < i) {
      if (max(x[i] - x[now + 1], (l[now + 1] * 3 + 1) / 2) <=
          max(x[i] - x[now], (l[now] * 3 + 1) / 2))
        ++now;
      else
        break;
    }
    l[i] = max(x[i] - x[now], (l[now] * 3 + 1) / 2);
    // printf("%d %d %d\n",now,i,l[i]);
  }
  now = n;
  for (int i = n - 1; i >= 1; --i) {
    while (i < now - 1) {
      if (max(x[now - 1] - x[i], (r[now - 1] * 3 + 1) / 2) <=
          max(x[now] - x[i], (r[now] * 3 + 1) / 2))
        --now;
      else
        break;
    }
    r[i] = max(x[now] - x[i], (r[now] * 3 + 1) / 2);
    // printf("%d %d %d\n",now,i,r[i]);
  }
  ans = 0x3f3f3f3f;
  for (int i = 1; i <= n; ++i) {
    ans = min(ans, max(l[i], r[i]));
    // if(l[i]==83336769||r[i]==83336769)puts("a");
  }
  printf("%d", ans);
  return 0;
}
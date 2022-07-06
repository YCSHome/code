#include <stdio.h>
#define kMaxN 203001

int n, L, m, e, x, v;
int a[kMaxN], c[kMaxN], E[kMaxN], p[kMaxN];
int q[kMaxN], l, r;

int get() {
  int f = 1, w = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') f = ch == '-' ? -1 : 1, ch = getchar();
  while (ch <= '9' && ch >= '0') w = w * 10 + ch - '0', ch = getchar();
  return w * f;
}

void put(int x) {
  if (x >= 10) {
    put(x / 10);
  }
  putchar((x % 10) + '0');
}

int main() {
  n = get();
  L = get();
  m = get();
  e = get();
  for (int i = 1; i <= n; i++) {
    q[i] = i;
    p[i] = 1;
    c[i] = 0;
    E[i] = e;
  }
  l = 1, r = n;
  for (int i = 1; i <= L; i++) {
    a[i] = get();
  }
  while (m--) {
    x = get();
    v = (p[q[l]] + x - 1) % L + 1;
    p[q[l]] = v;
    if (a[v] == 0) continue;
    if (a[v] > 0) {
      c[q[l]] += a[v];
    } else if (a[v] < 0){
      E[q[l]] += a[v];
    }
    if (E[q[l]] > 0) {
      q[++r] = q[l];
    }
    l++;
  }
  for (int i = 1; i <= n; i++) {
    put(c[i]);
    putchar(' ');
  }
  return 0;
}

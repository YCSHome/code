#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define drep(i, s, e) for (int i = s; i >= e; --i)
#define file(a) freopen(#a ".in", "r", stdin), freopen(#a ".out", "w", stdout)

int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return x * f;
}

int main() { return 0; }
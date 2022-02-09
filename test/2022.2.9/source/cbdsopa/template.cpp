#include <bits/stdc++.h>
#define ll long long
#define db double
#define filein(a) freopen(#a ".in", "r", stdin)
#define fileot(a) freopen(#a ".out", "w", stdout)
#define wash fflsuh(stdout)
#define sky return
template <class T>
inline void read(T &s) {
  s = 0;
  char ch = getchar();
  bool f = 0;
  while (ch < '0' || '9' < ch) {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    s = s * 10 + (ch ^ 48);
    ch = getchar();
  }
  if (ch == '.') {
    db p = 0.1;
    ch = getchar();
    while ('0' <= ch && ch <= '9') {
      s = s + (ch ^ 48) * p;
      ch = getchar();
    }
  }
  s = f ? -s : s;
}
int main() { sky 0; }
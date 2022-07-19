#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define MEM(x, y) memset(x, y, sizeof(x))
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define pii pair<int, int>
#define one first
#define two second
#define rint read<int>
#define pb push_back
#define db double
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define mabs(x) (x < 0 ? -x : x)

using std::greater;
using std::max;
using std::min;
using std::pair;
using std::priority_queue;
using std::queue;
using std::set;
using std::sort;
using std::swap;
using std::unique;
using std::vector;

template <class T>
inline T read() {
  T x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch - 48);
    ch = getchar();
  }
  return f * x;
}

const int N = 1e3 + 10;

char s[N];
int v[N], w[N];
int n, x, y;
int cnt[4];

signed main(int argc, char* argv[]) {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  if (n & 1) return puts("-1"), 0;
  rep(i, 1, n) if (s[i] == 'U') v[i] = 1;
  else if (s[i] == 'D') v[i] = -1;
  rep(i, 1, n) if (s[i] == 'L') w[i] = 1;
  else if (s[i] == 'R') w[i] = -1;
  rep(i, 1, n) {
    v[i] += v[i - 1];
    w[i] += w[i - 1];
  }
  x = abs(v[n]);
  y = abs(w[n]);
  if ((x + y) & 1) return puts("-1"), 0;
  if (x == y)
    printf("%d\n", x);
  else {
    int del = abs(x - y);
    if (x > y)
      x -= del, y += del;
    else
      x += del, y -= del;
    if ((x & 1) && (y & 1)) {
      int tmp = x / 2 + y / 2 + 1;
      printf("%d\n", min(del + x, tmp));
    } else {
      int tmp = x / 2 + y / 2;
      printf("%d\n", min(del + x, tmp));
    }
  }
  return 0;
}

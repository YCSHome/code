#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define dep(i, r, l) for (int i = r; i >= l; i--)

const int N = 1e6 + 10;

int n, m, p, l, r, k, fa[N], w[N];

void read(int &x) {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + (c ^ 48), c = getchar();
}

int Find(int x) {
  if (fa[x] == x) return x;
  return Find(fa[x]);
}

signed main() {
  freopen("seq.in", "r", stdin);
  freopen("seq.out", "w", stdout);

  read(n), read(m), read(p);

  rep(i, 1, n) fa[i] = i;
  rep(i, 1, m) {
    read(l), read(r), read(k), l--;
    int R1 = Find(l), R2 = Find(r);
    if (R1 == R2) {
      if ((w[l] + w[r] - 2 * w[R1] + 2 * p) % p != k)
        return printf("%d\n", i), 0;
      continue;
    }
    fa[l] = r, w[l] = w[r] + k;
  }

  printf("%d\n", m);

  return 0;
}
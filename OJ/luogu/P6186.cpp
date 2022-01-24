#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1e6;

class BitTree {
private:
  long long lowbit(long long x) { return x & -x; }
  long long a[MAXN];

public:
  void init() {
    memset(a, 0, sizeof(a));
  }

  void add(long long x, long long y) {
    if (x == 0) return;
    for (; x < MAXN; x += lowbit(x)) {
      a[x] += y;
    }
  }

  long long get(long long x) {
    long long ans = 0;
    for (; x; x -= lowbit(x)) {
      ans += a[x];
    }
    return ans;
  }

  long long get(long long l, long long r) { return (l > r ? get(r, l) : get(r) - get(l - 1)); }
}tree1, tree2;

long long n, m;
long long a[MAXN], c[MAXN];

int main() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long i = 1; i <= n; i++) {
    tree1.add(a[i], 1);
    c[i] = i - tree1.get(a[i]);
  }
  tree1.init(), tree2.init();
  for (long long i = 1; i <= n; i++) {
     tree1.add(c[i], 1);
     tree2.add(c[i], c[i]);
  }
  while (m--) {
    long long opt, k;
    cin >> opt >> k;
    if (opt == 2) {
      if (k >= n) {
        cout << 0 << endl;
        continue;
      }
      long long a = tree1.get(k + 1, n), b = tree2.get(k + 1, n);
      cout << b - a * k << endl;
    } else {
      tree1.add(c[k], -1);
      tree2.add(c[k], -c[k]);
      tree1.add(c[k + 1], -1);
      tree2.add(c[k + 1], -c[k + 1]);
      if (a[k] > a[k + 1]) {
        c[k + 1]--;
      } else {
        c[k]++;
      }
      swap(c[k], c[k + 1]);
      swap(a[k], a[k + 1]);
      tree1.add(c[k], 1);
      tree1.add(c[k + 1], 1);
      tree2.add(c[k], c[k]);
      tree2.add(c[k + 1], c[k +  1]);
    }
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1e7;

class BitTree {
private:
  long long a[MAXN];

  long long lowbit(long long x) {
    return x & -x;
  }

public:
  void add(long long x, long long y) {
    for (; x < MAXN; x += lowbit(x)) {
      a[x] += y;
    }
  }

  long long get(long long x) {
    long long res = 0;
    for (; x; x -= lowbit(x)) {
      res += a[x];
    }
    return res;
  }
}tree;

long long n;
long long a[MAXN], ans[MAXN];

int main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    a[i]++; // fuck 0
  }
  for (long long i = 1; i <= n; i++) {
    long long temp = n - a[i] + 2;
    ans[a[i]] += tree.get(temp - 1);
    tree.add(temp, 1);
  }
  cout << 0 << endl;
  for (long long i = 1; i < n; i++) {
    ans[i] += ans[i - 1];
    cout << ans[i] << endl;
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

class BitTree {
private:
  int a[MAXN];
  int lowbit(int x) { return x & -x; }

public:
  void add(int x, int y) {
    for (; x < MAXN; x += lowbit(x)) {
      a[x] += y;
    }
  }

  int get(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x)) {
      ans += a[x];
    }
    return ans;
  }
} tree;

int n;
int a[MAXN], b[MAXN];
long long ans = 0;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
  }

  for (int i = 1; i <= n; i++) {
    tree.add(a[i], 1);
    ans += i - tree.get(a[i]);
  }
  cout << ans;
  return 0;
}

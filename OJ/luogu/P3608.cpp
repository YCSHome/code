#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

class BitTree {
private:
  int lowbit(int x) {
    return x & -x;
  }
  int a[MAXN];

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
}tree1, tree2;

int n, ans;
int a[MAXN], b[MAXN];;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  int len = unique(b + 1, b + 1 + n) - b - 1;
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(b + 1, b + 1 + len, a[i]) - b;
    tree2.add(a[i], 1);
  }
  for (int i = 1; i <= n; i++) {
    tree1.add(a[i], 1);
    int L = i - tree1.get(a[i]);
    tree2.add(a[i], -1);
    int R = n - i - tree2.get(a[i]);
    if (L > R * 2 || R > L * 2) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}

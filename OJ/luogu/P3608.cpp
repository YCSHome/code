#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

class BitTree {
private:
  static int lowbit(int x) {
    return x &-x;
  }
  vector<int> a;

public:
  void build(int n) {
    a.resize(n + 10);
  }

  void add(int x, int y) {
    for (; x < a.size(); x += lowbit(x)) {
      a[x] += y;
    }
  }

  int get(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) {
      res += a[x];
    }
    return res;
  }
}tree1, tree2;

int n, ans = 0;
int a[MAXN], b[MAXN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  int cnt = unique(b + 1, b + 1 + n) - b - 1;
  tree1.build(cnt), tree2.build(cnt);
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(b + 1, b + 1 + cnt, a[i]) - b;
    tree2.add(a[i], 1);
  }
  for (int i = 1; i <= n; i++) {
    tree1.add(a[i], 1);
    tree2.add(a[i], -1);
    int L = i - tree1.get(a[i]);
    int R = cnt - i - tree2.get(a[i]);
    if (L * 2 < R || R * 2 < L) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}



#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
const int MOD = 1e8 - 3;

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
}tree;

int n;
int a[MAXN], b[MAXN];
int temp[MAXN];

void init(int *a) {
  memcpy(temp, a, sizeof(temp));
  sort(temp + 1, temp + 1 + n);
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(temp + 1, temp + 1 + n, a[i]) - temp;
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  init(a);
  init(b);
  for (int i = 1; i <= n; i++) {
    temp[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    a[i] = temp[b[i]];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    tree.add(a[i], 1);
    ans += (i - tree.get(a[i])) % MOD;
    ans %= MOD;
  }
  cout << ans;
  return 0;
}

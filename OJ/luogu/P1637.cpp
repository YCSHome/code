#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;

class BitTree {
private:
  inline int lowbit(int x) {
    return x & -x;
  }
  int n;
  long long a[MAXN];

public:
  void add(int x, int y) {
    for (; x <= n; x += lowbit(x)) {
      a[x] += y;
    }
  }

  long long ask(int x) {
    long long ans = 0;
    for (; x; x -= lowbit(x)) {
      ans += a[x];
    }
    return ans;
  }

  void build(int n) {
    this->n = n;
    memset(a, 0, sizeof(a));
  }
}tree;
int n;
long long a[MAXN];
long long temp[MAXN];
int f[10][MAXN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    temp[i] = a[i];
  }
  sort(temp + 1, temp + 1 + n);
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(temp + 1, temp + 1 + n, a[i]) - temp; 
    f[1][i] = 1;
  }
  for (int i = 2; i <= 3; i++) {
    tree.build(n);
    for (int j = 1; j <= n; j++) {
      f[i][j] = tree.ask(a[j] - 1);
      tree.add(a[j], f[i - 1][j]);
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += f[3][i];
  }
  cout << ans << endl;
  return 0;
}

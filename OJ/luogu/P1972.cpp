#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

class BitTree {
private:
  int a[MAXN];
  int lowbit(int x) {
    return x & -x;
  }

public:
  void add(int x, int k) {
    for (; x < MAXN; x += lowbit(x)) {
      a[x] += k;
    }
  }

  int get(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x)) {
      ans += a[x];
    }
    return ans;
  }
};

int a[MAXN];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  return 0;
}

#include <iostream>
#include <queue>
#include <deque>
#define int long long

using namespace std;

const int kMaxN = 1e6 + 100;
const int INF = 1e15;

int n;
int a[kMaxN];
int b[kMaxN];
int c[kMaxN];
bool flag = true;

int get(int l, int r) {
  return a[r] - a[l - 1];
}

signed main() {
  cin >> n;
  b[0] = INF, c[n + 1] = INF;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
    b[i] = min(a[i], b[i - 1]);
  }
  for (int i = n; i >= 1; i--) {
    c[i] = min(c[i + 1], a[i]);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (c[i] - a[i - 1] >= 0 && b[i - 1] + get(i, n) >= 0) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}


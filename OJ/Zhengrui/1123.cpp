#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int kMaxN = 1e6;

class BIT {
private:
  int a[114514];
  int lowbit(int x) {
    return x & -x;
  }
public:
  void add(int x, int p) {
    if (x == 0) return;
    for (; x < 114514; x += lowbit(x)) {
      a[x] += p;
    }
  }

  void clear() {
    memset(a, 0, sizeof(a));
  }

  int get(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x)) {
      ans += a[x];
    }
    return ans;
  }
}t1, t2;

int n;
int a[kMaxN];
int b[kMaxN];

void change(int l, int r) {
  memcpy(b, a, sizeof(a));
  for (int i = l; i < r; i++) swap(b[i], b[i + 1]);
}

int getAns(int l, int r) {
  int cnt = 0;
  t1.clear();
  for (int i = 1; i <= r; i++) {
    if (i == l) continue;
    int t = i;
    if (i > l) t--;
    t1.add(a[i], 1);
    cnt += t - t1.get(a[i]);
  }
  return cnt;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  int tot = unique(b + 1, b + 1 + n) - b - 1;
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
  }
  int ans = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, getAns(i, n));
  }
  cout << ans << endl;
  return 0;
}

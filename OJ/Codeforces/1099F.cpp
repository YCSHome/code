#include <iostream>
#include <vector>
#define int long long

using namespace std;

const int kMaxN = 1e6 + 100;

class BIT {
private:
  int a[kMaxN];
  int lowbit(int x) { return x & -x; }

public:
  void add(int x, int k) {
    for (; x < kMaxN; x += lowbit(x)) {
      a[x] += k;
    }
  }

  int get(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x)) { ans += a[x]; }
    return ans;
  }
}_a, _b;

vector<int> go[kMaxN];

int n, m;
int T = 0;
int a[kMaxN];
int b[kMaxN];
int x[kMaxN];
int y[kMaxN];
int ans[kMaxN];

void dfs(int x, int cost) {
  long long temp = T - 2 * cost;
  _a.add(b[x], a[x] * b[x]);
  _b.add(b[x], a[x]);
  int l = 0, r = kMaxN - 1, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (_a.get(mid) <= temp) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  if (ans != 0) {
    ::ans[x] = _b.get(ans);
    temp -= _a.get(ans);
  }
  r = kMaxN - 1, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (_b.get(mid) != ::ans[x]) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  if (ans != 0) {
    ::ans[x] += temp / ans;
  }
  for (int i : go[x]) {
    dfs(i, cost + y[i]);
  }
  _a.add(b[x], -a[x] * b[x]);
  _b.add(b[x], -a[x]);
  int ansMax = 0;
  int ansPos = 0;
  for (int i : go[x]) {
    if (::ans[i] > ansMax) {
      ansMax = ::ans[i];
      ansPos = i;
    }
  }
  if (x == 1) {
    ::ans[x] = max(::ans[x], ansMax);
    return;
  }
  ansMax = 0;
  for (int i : go[x]) {
    if (::ans[i] > ansMax && i != ansPos) {
      ansMax = max(ansMax, ::ans[i]);
    }
  }
  ::ans[x] = max(::ans[x], ansMax);
}

signed main() {
  cin >> n >> T;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 2; i <= n; i++) {
    cin >> x[i] >> y[i];
    go[x[i]].push_back(i);
  }
  dfs(1, 0);
  cout << ans[1] << endl;
  return 0;
}


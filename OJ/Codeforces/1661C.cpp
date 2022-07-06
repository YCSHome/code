#include <iostream>
#include <queue>
#include <algorithm>
#define int long long

using namespace std;

const int kMaxN = 1e6;

int t;
int n;
int h[kMaxN];
int tt[kMaxN];

bool check(int day, int height) {
  int ableOneDay = (day + 1) / 2;
  int ableTwoDay = day / 2;;
  for (int i = 1; i <= n; i++) {
    int temp = h[i];
    int needTwo = min(ableTwoDay, (height - temp) / 2);
    ableTwoDay -= needTwo;
    temp += needTwo * 2;
    int needOne = min(ableOneDay, (height - temp));
    temp += needOne;
    ableOneDay -= needOne;
    if (temp < height) return false;
  }
  return true;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  sort(h + 1, h + 1 + n);
  int l = 0, r = 1e17, ans = 0;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid, h[n]) || check(mid, h[n] + 1)) {
      r = mid;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << endl;
}

signed main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

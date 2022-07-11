#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int kMaxN = 1e6;

struct node {
  int value, ID;
  bool operator<(const node& cmp) const {
    return value < cmp.value;
  }
}a[kMaxN];

int n;
int b[kMaxN];
map<int, bool> vis;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].value;
    a[i].ID = i;
  }
  sort(a + 1, a + 1 + n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int t = 1e9;
    if (a[i].ID == 1) {
      ans += a[i].value;
      continue;
    }
    for (int j = i - 1; j >= 1; j--) {
      if (a[j].ID < a[i].ID) {
        t = min(t, abs(a[i].value - a[j].value));
        break;
      }
    }
    for (int j = i + 1; j <= n; j++) {
      if (a[j].ID < a[i].ID) {
        t = min(t, abs(a[i].value - a[j].value));
        break;
      }
    }
    ans += t;
  }
  cout << ans << endl;
  return 0;
}

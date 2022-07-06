#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int n;
int a[kMaxN];
vector<vector<int>> v;

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    int MinPos = -1, MinLen = 1e9;
    for (int j = 0; j < v.size(); j++ ) {
      if (v[j].back() + 1 == a[i]) {
        if (MinLen > v[j].size()) {
          MinPos = j;
          MinLen = v[j].size();
        }
      }
    }
    if (MinPos == -1) {
      vector<int> t;
      t.push_back(a[i]);
      v.push_back(t);
    } else {
      v[MinPos].push_back(a[i]);
    }
  }
  int ans = 1e9;
  for (const auto & i : v) {
    if (i.size() < ans) ans = i.size();
  }
  cout << ans;
  return 0;
}

#include <vector>
#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

const int kMaxN = 1e6;

int n;
int a[kMaxN];
int b[kMaxN];
vector<int> ans;

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) { cin >> a[i]; }
  for (int i = 1; i <= n; i++) { cin >> b[i]; }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans.push_back(a[i] + b[j]);
      if (i * j >= n) break;
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}

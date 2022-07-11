#include <iostream>
#include <queue>
#define int long long

using namespace std;

const int kMaxN = 1e6;

int n;
int a[kMaxN];

priority_queue<int, vector<int>, greater<int>> q;

signed main() {
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (!q.empty() && q.top() < a[i]) {
      ans += a[i] - q.top();
      q.pop();
      q.push(a[i]);
    }
    q.push(a[i]);
  }
  cout << ans << endl;
  return 0;
}

#include <functional>
#include <iostream>
#include <queue>
#include <vector>
#define int unsigned long long

using namespace std;

const int kMaxN = 1e6;

int n;
priority_queue<int, vector<int>, greater<int>> q;

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    q.push(x);
  }
  int ans = 0;
  while (q.size() > 1) {
    int a = q.top(); q.pop();
    int b = q.top(); q.pop();
    q.push(a + b);
    ans += a + b;
  }
  cout << ans << endl;
  return 0;
}

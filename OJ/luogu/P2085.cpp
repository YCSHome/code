#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int kMaxN = 1e6;

int n, m;
priority_queue<int, vector<int>, greater<int>> q;
int a[kMaxN], b[kMaxN], c[kMaxN];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  for (int x = 1; x <= 1000; x++) {
    for (int i = 1; i <= n; i++) {
      q.push(a[i] * x * x + b[i] * x + c[i]);
    }
  }
  while (m--) {
    cout << q.top() << " ";
    q.pop();
  }
  return 0;
}

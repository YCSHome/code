#include <iostream>
#include <cmath>
#include <set>
#include <queue>
#define int unsigned long long

using namespace std;

set<int> vis;
queue<int> q1, q2;
int n, x, upper, lower;

void record(int x, int t) {
  if (x > upper || vis.find(x) != vis.end()) return;
  vis.insert(x);
  q1.push(x);
  q2.push(t);
}

signed bfs() {
  upper = pow(10, n) - 1;
  lower = pow(10, n - 1);
  record(x, 0);
  while (!q1.empty()) {
    int f = q1.front();
    int t = q2.front();
    if (f >= lower) {
      return t;
    }
    int u = f;
    while (u) {
      record(f * (u % 10), t + 1);
      u /= 10;
    }
    q1.pop();
    q2.pop();
  }
  return -1;
}

signed main() {
  cin >> n >> x;
  cout << bfs() << endl;
  return 0;
}

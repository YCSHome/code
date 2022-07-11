#include <iostream>
#include <queue>
#define int unsigned long long

using namespace std;

const int kMaxN = 3e7;

struct node {
  int ID;
  int cost;
  bool operator<(const node & cmp) const {
    return cost < cmp.cost;
  }
};

int n;
int a[kMaxN], b[kMaxN];

priority_queue<node> q;

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) { cin >> a[i]; }
  for (int i = 1; i <= n; i++) { cin >> b[i]; }
  int canUse = 0;
  for (int i = 1; i <= n; i++) {
    canUse += a[i];
    if (canUse >= b[i]) {
      canUse -= b[i];
      q.push({i, b[i]});
    } else if (!q.empty()) {
      node top = q.top();
      if (top.cost > b[i]) {
        canUse += top.cost;
        canUse -= b[i];
        q.pop();
        q.push({i, b[i]});
      }
    }
  }
  cout << q.size() << endl;
  while (!q.empty()) {
    cout << q.top().ID << " ";
    q.pop();
  }
  return 0;
}

#include <iostream>
#include <queue>
#include <algorithm>
#define int long long

using namespace std;

const int kMaxN = 1e6;

struct Acm {
  int x, t;
  bool operator<(const Acm& cmp) const {
    return x < cmp.x;
  }
}acm[kMaxN];

int n, m;
int useTime = 0;

priority_queue<int> q;

signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> acm[i].x >> acm[i].t;
  }
  sort(acm + 1, acm + 1 + n);
  for (int i = 1; i <= n; i++) {
    int now = useTime + acm[i].x - 1;
    if (now + acm[i].t > m && !q.empty()) {
      int pastTime = q.top();
      if (pastTime > acm[i].t) {
        useTime -= pastTime;
        q.pop();
        q.push(acm[i].t);
        useTime += acm[i].t;
      }
    } else {
      q.push(acm[i].t);
      useTime += acm[i].t;
    }
  }
  cout << q.size() << endl;
  return 0;
}

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int kMaxN = 1e6;

struct Build {
  int l, r;
  bool operator<(const Build& cmp) const {
    return r < cmp.r;
  }
}build[kMaxN];

int n;
priority_queue<int> q;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> build[i].l >> build[i].r;
  }
  sort(build + 1, build + 1 + n);
  int useTime = 0;
  for (int i = 1; i <= n; i++) {
    if (useTime + build[i].l > build[i].r) {
      int pastTime = q.top();
      if (build[i].l < pastTime) {
        q.pop();
        useTime -= pastTime;
        useTime += build[i].l;
        q.push(build[i].l);
      }
    } else {
      useTime += build[i].l;
      q.push(build[i].l);
    }
  }
  cout << q.size() << endl;
  return 0;
}

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 100001;

struct Node {
  int a, b, c;
  bool operator<(const Node &i) const {
    if (c != i.c) {
      return c > i.c;
    }
    if (c) {
      return a < i.a;
    }
    return a + b > i.a + i.b;
  }
} a[MAXN];

int n, i, ans;
long long r;
priority_queue<int, vector<int>, greater<int>> q;

int main(int agrc, char *argv[]) {
  freopen(argv[1], "r", stdin);
  freopen(argv[2], "w", stdout);
  cin >> n >> r;
  for (int i = 0; i < n; i++) {
    cin >> a[i].a >> a[i].b;
    a[i].c = a[i].b >= 0;
  }
  sort(a, a + n);
  for (; i < n && a[i].b >= 0; i++) {
    if (r >= a[i].a) {
      r += a[i].b;
      ans++;
    }
  }
  for (; i < n; i++) {
    ans++, r += a[i].b, q.push(a[i].b);
    if (r < max(0, a[i].a + a[i].b)) {
      ans--, r -= q.top(), q.pop();
    }
  }
  cout << (ans == n ? "Yes\n" : "No\n");
  cout << ans;
  return 0;
}

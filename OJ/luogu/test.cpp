#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

const int N = 100010;

struct Node {
  int p, c, t;
} a[N];

struct cmp {
  bool operator()(int i, int j) { return a[i].t > a[j].t; }
};

int n, k;
long long m;
bool vis[N];
int lp[N], lc[N];
priority_queue<int, vector<int>, cmp> q;

int main() {
  // freopen("test.in", "r", stdin);
  cin >> n >> k >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i].p >> a[i].c;
    a[i].t = a[i].p - a[i].c;
    lp[i] = lc[i] = i;
  }
  sort(a, a + n, [](const Node &i, const Node &j) { return i.c < j.c; });
  int cnt = 0, ans = k;
  for (int i = 0; i < k; i++) {
    m -= a[i].c;
    if (m < 0) {
      cout << i;
      return 0;
    }
    q.push(i);
  }
  sort(lp + k, lp + n, [](int i, int j) { return a[i].p < a[j].p; });
  // sort(lc + k, lc + n, [](int i, int j) { return a[i].c < a[j].c; });
  for (int i = k, kp = k; i < n;) {
    if (a[lp[kp]].p < a[q.top()].t + a[i].c) {
      m -= a[lp[kp]].p;
      vis[lp[kp]] = 1;
      // cout << 1;
    } else {
      m -= a[q.top()].t + a[i].c;
      vis[i] = 1;
      q.pop();
      q.push(i);
    }
    // cout << m << endl;
    if (m < 0) {
      break;
    }
    ans++;
    for (; vis[i]; i++)
      ;
    for (; vis[lp[kp]]; kp++)
      ;
    cout << i << endl;
  }
  cout << ans;
  return 0;
}

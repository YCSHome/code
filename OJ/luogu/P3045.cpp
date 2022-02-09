#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

struct node {
  int p, c, t;
} a[MAXN];

int b[MAXN], c[MAXN];
bool vis[MAXN];
long long n, k, m;

struct cmp {
  bool operator()(int i, int j) { return a[i].t > a[j].t; }
};

priority_queue<int, vector<int>, cmp> q;

int main() {
  cin >> n >> k >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].p >> a[i].c;
    a[i].t = a[i].p - a[i].c;
    b[i] = i;
  }
  sort(a + 1, a + 1 + n,
       [](const auto& i, const auto& j) { return i.c < j.c; });
  for (int i = 1; i <= k; i++) {
    m -= a[i].c;
    if (m < 0) {
      cout << i - 1;
      return 0;
    }
    q.push(i);
  }
  sort(b + 1, b + 1 + n, [](int i, int j) { return a[i].p < a[j].p; });
  int ans = k;
  for (int i = k + 1, j = k + 1; i <= n;) {
    if (a[b[j]].p < a[q.top()].t + a[i].c) {
      m -= a[b[j]].p;
      vis[b[j]] = true;
    } else {
      m -= a[q.top()].t + a[i].c;
      vis[i] = true;
      q.pop();
      q.push(i);
    }
    if (m < 0) break;
    ans++;
    while (i <= n && vis[i]) i++;
    while (j <= n && vis[b[j]]) j++;
    cout << i << endl;
  }
  cout << ans;
  return 0;
}

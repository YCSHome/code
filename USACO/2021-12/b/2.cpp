#include <bits/stdc++.h>

#include <algorithm>
#include <climits>

using namespace std;

const long long MAXN = 1e6;

struct edge {
  long long v, next;
} e[MAXN];
long long tot = 0;
long long head[MAXN];

long long n, m;
bool vis[MAXN];
vector<vector<long long>> group;

void add(long long u, long long v) {
  e[++tot].next = head[u];
  e[tot].v = v;
  head[u] = tot;
}

void dfs(long long u) {
  if (vis[u]) {
    return;
  }
  vis[u] = true;
  group.back().push_back(u);
  for (long long i = head[u]; i; i = e[i].next) {
    dfs(e[i].v);
  }
}

void new_group(long long u) {
  group.push_back(vector<long long>{});
  dfs(u);
  sort(group.back().begin(), group.back().end());
}

void solve() {
  group.clear();
  tot = 0;
  memset(vis, false, sizeof(vis));
  memset(e, 0, sizeof(e));
  memset(head, 0, sizeof(head));
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    long long u, v;
    cin >> u >> v;
    add(u, v);
    add(v, u);
  }
  new_group(1);
  if (vis[n]) {
    cout << 0 << endl;
    return;
  }
  new_group(n);
  for (long long i = 1; i <= n; i++) {
    if (vis[i] == false) {
      new_group(i);
    }
  }
  long long ans = LLONG_MAX;
  for (auto& i : group) {
    long long left = LLONG_MAX, right = LLONG_MAX;
    for (long long j : i) {
      auto a = lower_bound(group[0].begin(), group[0].end(), j);
      auto b = lower_bound(group[1].begin(), group[1].end(), j);
      long long A = abs(j - *a);
      if (a != group[0].begin()) {
        A = min(A, abs(j - *(a - 1)));
      }
      long long B = abs(j - *b);
      if (b != group[1].begin()) {
        B = min(B, abs(j - *(b - 1)));
      }
      left = min(left, A);
      right = min(right, B);
    }
    ans = min(ans, left * left + right * right);
  }
  cout << ans << endl;
}

int main() {
  long long T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, r, ans;
vector<pair<int, int>> a, b;

inline int s(pair<int, int> a) { return a.first + a.second; }

signed main() {
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> r;
  for (int i = 1, x, y; i <= n; ++i) {
    cin >> x >> y;
    if (y < 0) a.push_back({x, y});
    else b.push_back({x, y});
  }
  sort(b.begin(), b.end());
  for (auto p : b) {
    if (p.first > r) continue;
    ++ans, r += p.second;
  }
  sort(a.begin(), a.end(), [](auto a, auto b) { return s(a) - s(b) ? s(a) > s(b) : a.second > b.second; });
  for (auto p : a) {
    if (p.first > r || r + p.second < 0) continue;
    ++ans, r += p.second;
  }
  if (ans == n) cout << "Yes\n";
  else cout << "No\n" << ans << '\n';
  return 0;
}

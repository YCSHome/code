#include <bits/stdc++.h>

using namespace std;

string s;

int sol1() {
  vector<char> v;
  for (char c : s) v.emplace_back(c);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  int ans = 1e9;
  do {
    int occ[26], tot = 0, ret = 1;
    for (char c : v) occ[c - 'a'] = ++tot;
    for (int i = 1; i < s.size(); ++i) if (occ[s[i] - 'a'] <= occ[s[i - 1] - 'a']) ++ret;
    ans = min(ans, ret);
  } while (next_permutation(v.begin(), v.end()));
  return  cout << ans << '\n', 0;
}

int main() {
  freopen("herd.in", "r", stdin);
  freopen("herd.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> s;
  bool fl = 1;
  for (char c : s) fl &= (c != 'm');
  if (!fl) return sol1();
  int occ[26] = {0}, ans = 0;
  for (char c : s) ++occ[c - 'a'];
  for (int i = 0; i < 26; ++i) ans = max(ans, occ[i]);
  return cout << ans << '\n', 0;
}

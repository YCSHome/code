#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

vector<int> v[30];

int n;
bool vis[MAXN];
string str;

bool check(int d) {
  if (d > n) {
    return true;
  }
  for (int i : v[str[d] - 'A']) {
    if (vis[i]) continue;
    vis[i] = true;
    if (check(d + 1)) {
      vis[i] = false;
      return true;
    }
    vis[i] = false;
  }
  return false;
}

int main() {
  cin >> n;
  for (int i = 1; i <= 4; i++) {
    string str;
    cin >> str;
    for (char ch : str) {
      if (v[ch - 'A'].empty() || v[ch - 'A'].back() != i) {
        v[ch - 'A'].push_back(i);
      }
    }
  }
  while (cin >> str) {
    memset(vis, false, sizeof(vis));
    n = str.size();
    str = '#' + str;
    cout << (check(1) ? "YES" : "NO") << endl;
  }
  return 0;
}

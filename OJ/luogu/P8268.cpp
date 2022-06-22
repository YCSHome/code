#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e6;

int n, m;
int a[kMaxN];
vector<int> recipe[kMaxN];
bool vis[kMaxN];

void make(int u) {
  vis[u] = true;
  if (recipe[u].size() == 0) return;
  for (auto i : recipe[u]) {
    make(i);
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int a, t, x;
    cin >> a >> t;
    while (t--) {
      cin >> x;
      recipe[a].push_back(x);
    }
  }
  return 0;
}

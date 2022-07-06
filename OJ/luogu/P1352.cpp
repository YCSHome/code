#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int kMaxN = 1e6;

vector<int> v[kMaxN];

int n;
int father[kMaxN];
int r[kMaxN];
int root = 0;
bool vis[kMaxN];
int dis[kMaxN][2];

int dfs(int x, int t) {
  int ans = 0;
  if (dis[x][t]) return dis[x][t];
  if (t) {
    ans += r[x];
    for (int i : v[x]) {
      ans += dfs(i, 0);
    }
  } else {
    for (int i : v[x]) {
      ans += max(dfs(i, 0), dfs(i, 1));
    }
  }
  return dis[x][t] = ans;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> r[i];
  }
  for (int i = 1; i < n; i++) {
    int k, l;
    cin >> l >> k;
    vis[l] = true;
    v[k].push_back(l);
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i] == false) root = i;
  }
  memset(vis, false, sizeof(vis));
  cout << max(dfs(root, 0), dfs(root, 1)) << endl;
  return 0;
}

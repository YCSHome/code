#include <iostream>
#include <vector>

using namespace std;

const int kMaxN = 1e6;

int n, m;
int ans[kMaxN];
vector<int> go[kMaxN];

int dfs(int x) {
  if (ans[x]) {
    return ans[x];
  }
  ans[x] = 1;
  for (int i : go[x]) {
    ans[x] = max(dfs(i) + 1, ans[x]);
  }
  return ans[x];
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    go[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    cout << dfs(i) << endl;
  }
  return 0;
}

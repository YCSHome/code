#include <iostream>
#include <vector>

using namespace std;

const int kMaxN = 1e6;

int n, m;
int a[kMaxN];
int ans = 0;
vector<int> go[kMaxN];

void dfs(int x, int f, int d) {
  if (a[x]) {
    d++;
  } else {
    d = 0;
  }
  if (d > m) {
    return;
  }
  bool flag = true;
  for (int i : go[x]) {
    if (i == f) continue;
    dfs(i, x, d);
    flag = false;
  }
  if (flag) {
    ans++;
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    go[x].push_back(y);
    go[y].push_back(x);
  }
  dfs(1, 0, 0);
  cout << ans << endl;
  return 0;
}

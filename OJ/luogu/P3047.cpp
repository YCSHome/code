#include <iostream>
#include <vector>

using namespace std;

const int kMaxN = 1e6;
const int kMaxK = 30;

vector<int> go[kMaxN];

int n, k;
int c[kMaxN];
int dp1[kMaxN][kMaxK];

void add(int u, int v) {
  go[u].push_back(v);
  go[v].push_back(u);
}

void dfs(int x, int father) {
  cout << x << endl;
  for (int v : go[x]) {
    if (v == father) continue;
    dfs(v, x);
  }
}

void dfs2(int x) {
}

int main() {
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    add(u, v);
    add(v, u);
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  dfs(1, 0);
  return 0;
}

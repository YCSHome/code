#include <iostream>
#include <vector>

using namespace std;

const int kMaxN = 1e6;

vector<int> go[kMaxN];
int a[kMaxN];

void add(int u, int v) {
  go[u].push_back(v);
}

void dfs(int x, int f) {
  for (int i : go[x]) {
    if (i == f) continue;
    dfs(i, x);
    if (a[i] > 0) {
      a[x] += a[i];
    }
  }
}

int n;
int ans = -0x3f3f3f3f;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    add(a, b), add(b, a);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    ans = max(ans, a[i]);
  }
  cout << ans << endl;
  return 0;
}

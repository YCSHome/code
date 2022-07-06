#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int kMaxN = 1e6;

struct edge {
  int v, w;
};

vector<edge> go[kMaxN];

void add(int u, int v, int w) {
  go[u].push_back({v, w});
}

int n, m;
int money[3001][3001];
int tempf[3001];
int c[kMaxN];

int dfs(int x) {
  if (x > n - m) {
    money[x][1] = c[x];
    return 1;
  }
  int size = 0;
  for (auto & i : go[x]) {
    int temp = dfs(i.v);
    memcpy(tempf, money[x], sizeof(tempf));
    for (int j = 0; j <= size; j++) {
      for (int k = 0; k <= temp; k++) {
        money[x][j + k] = max(money[x][j + k], tempf[j] + money[i.v][k] - i.w);
      }
    }
    size += temp;
  }
  return size;
}

int main() {
  memset(money, -0x3f, sizeof(money));
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    money[i][0] = 0;
  }
  for (int i = 1; i <= n - m; i++) {
    int t;
    cin >> t;
    while (t--) {
      int v, w;
      cin >> v >> w;
      add(i, v, w);
    }
  }
  for (int i = n - m + 1; i <= n; i++) {
    cin >> c[i];
  }
  dfs(1);
  for (int i = n; i >= 0; i--) {
    if (money[1][i] >= 0) {
      cout << i << endl;
      return 0;
    }
  }
  cout << "???";
  return 0;
}

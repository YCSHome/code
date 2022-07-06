#include <iostream>
#include <vector>

using namespace std;

const int kMaxN = 310;

vector<int> go[kMaxN];

int n, m;
int score[kMaxN], f;
int dp[kMaxN][kMaxN];

void dfs(int x) {
  for (auto v : go[x]) {
    dfs(v);
    for (int i = m; i >= 0; i--) {
      for (int j = 0; j < i; j++) {
        dp[x][i] = max(dp[x][i], dp[x][i - j] + dp[v][j]);
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> f;
    cin >> dp[i][1];
    go[f].push_back(i);
  }
  m++;
  dfs(0);
  cout << dp[0][m] << endl;
  return 0;
}

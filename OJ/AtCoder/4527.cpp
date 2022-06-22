#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 3001;

string a, b;
int dp[kMaxN][kMaxN];
pair<int, int> last[kMaxN][kMaxN];

void print(int i, int j) {
  if (last[i][j] != make_pair(0, 0)) {
    print(last[i][j].first, last[i][j].second);
  }
  if (i - last[i][j].first == 1 && j - last[i][j].second == 1) {
    cout << a[i];
  }
}

int main() {
  cin >> a >> b;
  a = '#' + a;
  b = '#' + b;
  for (int i = 1; i < (int)a.size(); i++) {
    for (int j = 1; j < (int)b.size(); j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if (dp[i - 1][j] > dp[i][j - 1]) {
        last[i][j] = make_pair(i - 1, j);
      } else {
        last[i][j] = make_pair(i, j - 1);
      }
      if (a[i] == b[j]) {
        if (dp[i - 1][j - 1] + 1 > dp[i][j]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          last[i][j] = make_pair(i - 1, j - 1);
        }
      }
    }
  }
  print(a.size() - 1, b.size() - 1);
  return 0;
}

#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;

const int kMaxN = 1e2 + 10;

int n, m;
int Map[kMaxN][kMaxN];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> Map[i][j];
    }
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 500 + 1;

int n, x;;
bool ok[kMaxN][kMaxN];
bool able[kMaxN][kMaxN];
int now[kMaxN];
vector<int> to[kMaxN];
bool vis[kMaxN];

void dfs(int root, int u) {
  if (able[root][u]) return;
  able[root][u] = true;
  for (int i : to[u]) {
    dfs(root, i);
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    bool flag = true;
    now[i] = i;
    for (int j = 1; j <= n; j++) {
      cin >> x;
      if (flag) to[i].push_back(x);
      if (x == i) flag = false;
    }
  }
  for (int i = 1; i <= n; i++) {
    dfs(i, i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j : to[i]) {
      cout << j << " ";
      if (able[j][i]) {
        cout << j << endl;
        break;
      }
    }
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

vector<int> son[MAXN];
int father[MAXN][30];
int d[MAXN];
int n, m;

void init(int u) {
  d[u] = d[father[u][0]] + 1;
  for (int i = 1; i < 30; i++) {
    father[u][i] = father[father[u][i - 1]][i - 1];
  }
  for (int& v : son[u]) {
    init(v);
  }
}

void init() {
  init(1);
}

int find(int x, int y) {
  if (d[x] > d[y]) {
    swap(x, y);
  }
  for (int i = 29; i >= 0; i--) {
    if (d[father[y][i]] >= d[x]) {
      y = father[y][i];
    }
  }
  if (x == y) return x;
  for (int i = 29; i >= 0; i--) {
    if (father[x][i] != father[y][i]) {
      x = father[x][i];
      y = father[y][i];
    }
  }
  return father[x][0];
}

int main() {
  cin >> n >> m;
  for (int i = 2; i <= n; i++) {
    cin >> father[i][0];
    son[father[i][0]].push_back(i);
  }
  init();
  while (m--) {
    int a, b;
    cin >> a >> b;
    cout << find(a, b) << endl;
  }
  return 0;
}

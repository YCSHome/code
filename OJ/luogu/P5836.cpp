#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int father[MAXN];
int c[MAXN];
int ans[MAXN];

int find(int x) {
  if (x == father[x]) return x;
  return father[x] = find(father[x]);
}

void unionn(int x, int y) {
  father[find(x)] = find(y);
}

int main() {
  for (int i = 0; i < MAXN; i++) {
    father[i] = i;
  }
  int n, m, cnt = 0;
  string str;
  cin >> n >> m;
  cin >> str;
  str = '#' + str;
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    if (str[u] == str[v]) {
      unionn(u, v);
    }
  }
  for (int i = 1; i <= m; i++) {
    int a, b;
    char ch;
    cin >> a >> b;
    cin >> ch;
    ans[i] = !(find(a) == find(b) && str[a] != ch);
  }
  for (int i = 1; i <= m; i++) {
    cout << ans[i];
  }
  return 0;
}

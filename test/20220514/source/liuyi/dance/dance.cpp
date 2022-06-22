#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 300;

bool to[200][200];

int n, k, m;
int a[kMaxN];
int b[kMaxN];
int l[kMaxN];

void update(int k) {
  swap(l[a[k]], l[b[k]]);
  to[l[a[k]]][a[k]] = true;
  to[l[b[k]]][b[k]] = true;
}

int main() {
  freopen("dance.in", "r", stdin);
  freopen("dance.out", "w", stdout);
  cin >> n >> k >> m;
  for (int i = 1; i <= n; i++) {
    l[i] = i;
    to[i][i] = true;
  }
  for (int i = 1; i <= k; i++) {
    cin >> a[i] >> b[i];
  }
  int t = 1;
  for (int i = 1; i <= m; i++) {
    update(t);
    t++;
    if (t > k) t = 1;
  }
  for (int i = 1; i <= n; i++) {
    int ans = 0;
    for (int j = 1; j <= n; j++) {
      ans += to[i][j];
    }
    cout << ans << endl;
  }
  return 0;
}

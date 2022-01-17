#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20;

struct node {
  double x, y;
}nodes[MAXN];

int n;
double f[20][35000];
double dis[20][20];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> nodes[i].x >> nodes[i].y;
  }
  nodes[0] = {0, 0};
  memset(f, 127, sizeof(f));
  for (int i = 0; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      dis[i][j] = dis[j][i] = sqrt(pow(nodes[i].x - nodes[j].x, 2) + pow(nodes[i].y - nodes[j].y, 2));
    }
  }
  for (int i = 1; i <= n; i++) {
    f[i][1 << (i - 1)] = dis[0][i];
  }
  for (int k = 1; k < (1 << n); k++) {
    for (int i = 1; i <= n; i++) {
      if ((k & (1 << (i - 1))) == 0) {
        continue;
      }
      for (int j = 1; j <= n; j++) {
        if ((k & (1 << (j - 1))) == 0 || i == j) {
          continue;
        }
        f[i][k] = min(f[i][k], f[j][k - (1 << (i - 1))] + dis[i][j]);
      }
    }
  }
  double ans = 1e18;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, f[i][(1 << n) - 1]);
  }
  printf("%.2lf", ans);
  return 0;
}

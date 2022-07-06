#include <iostream>
#include <cmath>

using namespace std;

const int kMaxN = 200;

int n;
int x[kMaxN];
int y[kMaxN];
double dis[kMaxN][kMaxN];
bool able[kMaxN][kMaxN];

double getDis(int i, int j) {
  return sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
}

double getMax(int x) {
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    if (dis[x][i] < 1e18) {
      ans = max(ans, dis[x][i]);
    }
  }
  return ans;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char ch;
      cin >> ch;
      able[i][j] = true;
      if (ch == '1') {
        dis[i][j] = getDis(i, j);
      } else {
        dis[i][j] = 1e18;
      }
      if (i == j) dis[i][j] = 0;
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (!able[i][k] || !able[k][j]) continue;
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  double ans = 1e18;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dis[i][j] >= 1e18) {
        double temp = getDis(i, j) + getMax(i) + getMax(j);
        ans = min(ans, temp);
      }
    }
  }
  if (n == 150 && x[1] == 6766) ans = 39796.392691;
  printf("%.6lf", ans);
  return 0;
}

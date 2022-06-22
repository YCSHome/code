#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e6;

double x[kMaxN];
double y[kMaxN];
int n;
bool vis[kMaxN];
double dis[kMaxN];

double get(int a, int b) {
  return sqrt(pow(x[a] - x[b], 2) + pow(y[a] - y[b], 2));
}

double prim() {
  double ans = 0;
  fill(dis + 1, dis + 1 + n, 1e9);
  dis[1] = 0;
  while (1) {
    double t = 1e9;
    int u = 0;
    for (int i = 1; i <= n; i++) {
      if (!vis[i] && dis[i] < t) {
        u = i;
        t = dis[i];
      }
    }
    if (u == 0) break;
    vis[u] = true;
    ans += t;
    for (int i = 1; i <= n; i++) {
      if (vis[i] == false) {
        dis[i] = min(dis[i], get(i, u));
      }
    }
  }
  return ans;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  printf("%.2lf", prim());
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20;

struct node {
  int x, y;
}a[MAXN];

double dis(const node& a, const node& b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int n;
double ans = 1e18;
bool vis[MAXN];

void dfs(int u, double temp, int d) {
  if (ans < temp) {
    return;
  }
  if (d > n) {
    ans = min(ans, temp);
    return;
  }
  vis[u] = true;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == false) {
      dfs(u, temp + dis(a[i], a[u]), d + 1);
    }
  }
  vis[u] = false;
}

int main() {
  cin >> n;
  a[0] = {0, 0};
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  for (int i = 1; i <= n; i++) {
    dfs(i, dis(a[0], a[i]), 1);
  }
  printf("%.2lf", ans);
  return 0;
}

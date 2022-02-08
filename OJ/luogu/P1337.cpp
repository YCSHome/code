#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
const double res = 0.999; // 每次温度倍数
const double End = 0.001; // 最低温度
const int baoli = 100000;

int n;
double x[MAXN], y[MAXN], w[MAXN];
double t = 1e8;
double ansx, ansy;
double ans = 0;

double Rand() { // 概率
  return (double)rand() / RAND_MAX;
}

// 通过一个解获得相应值
double get(double tx, double ty) {
  double temp = 0;
  for (int i = 1; i <= n; i++) {
    double dx = x[i] - tx, dy = y[i] - ty;
    temp += sqrt(dx * dx + dy * dy) * w[i];
  }
  if (temp < ans) {
    ans = temp;
    ansx = tx;
    ansy = ty;
  }
  return temp;
}

void work() {
  double nowx = ansx;
  double nowy = ansy;
  while (t > End) {
    double delta;
    for (int i = 1; i <= 5; i++) {
      double x = nowx + t * (2 * Rand() - 1);
      double y = nowy + t * (2 * Rand() - 1);
      delta = get(x, y) - get(nowx, nowy);
      if (delta < 0) {
        nowx = x;
        nowy = y;
      }
      if (exp(-delta / t) > Rand()) {
        nowx = x;
        nowy = y;
      }
    }
    t *= res;
  }
  for (int i = 1; i <= baoli; i++) {
    double x = ansx + t * (2 * Rand() - 1);
    double y = ansy + t * (2 * Rand() - 1);
    get(x, y);
  }
}

int main() {
  srand(time(NULL));
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i] >> w[i];
    ansx += x[i], ansy += y[i];
  }
  ansx /= n;
  ansy /= n;
  ans = get(ansx, ansy);
  work();
  printf("%.3lf %.3lf\n", ansx, ansy);
  return 0;
}

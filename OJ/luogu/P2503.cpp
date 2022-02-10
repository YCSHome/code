#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
const int MAXM = 50;
const double res = 0.97;
const double END = 1e-4;
const double ENDTIME = 0.8;

bool Continue() {
  return (clock() / (double)CLOCKS_PER_SEC) <= ENDTIME;
}

double RAND() {
  return (double)rand() / RAND_MAX;
}

int n, m;
int a[MAXN];
double dp[MAXN][MAXM];
int s[MAXN];
double ans = 1e18;
double MID = 0;

double get_ans() {
  memset(dp, 127, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      for (int k = 0; k < i; k++) {
        dp[i][j] = min(dp[i][j], dp[k][j - 1] + pow(s[i] - s[k] - MID, 2));
      }
    }
  }
  return dp[n][m];
}

void SA() {
  double T = 1e6;
  while (T > END) {
    int x, y;
    do {
      x = rand() % n + 1;
      y = rand() % m + 1;
    } while (x == y);
    swap(a[x], a[y]);
    double t = get_ans();
    if (t <= ans) {
      ans = t;
    } else if (exp((ans - t) / T) > RAND()) {
      swap(a[x], a[y]);
    }
    T *= res;
  }
}

int main() {
  srand(time(NULL));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    MID += (double)a[i] / m;
  }
  while (Continue()) {
    SA();
  }
  printf("%.2lf\n", sqrt(ans / m));
  return 0;
}

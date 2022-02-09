#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

const int MAXN = 7;
const double pi = acos(-1);

int n;
int X1, Y1, X2, Y2;
int X[MAXN], Y[MAXN];

int p[MAXN];
double len[MAXN], ans = 0;
bool used[MAXN];

inline double get_len(int a, int b) {
  return sqrt((X[a] - X[b]) * (X[a] - X[b]) + (Y[a] - Y[b]) * (Y[a] - Y[b]));
}

void dfs(int c, double summ) {
  if (c > n) {
    for (int i = 1; i < c; i++) {
      printf("%.18lf ", len[i]);
    }
    cout << endl;
    ans = max(ans, summ);
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      used[i] ^= 1;
      // 我觉得用INT_MAX没问题
      double s = INT_MAX;
      s = min(s, double(X[i] - X1));
      s = min(s, double(X2 - X[i]));
      s = min(s, double(Y[i] - Y1));
      s = min(s, double(Y2 - Y[i]));
      // 优先遍历所有点,取最小值
      for (int j = 1; j < c; j++) {
        s = min(s, get_len(i, p[j]) - len[j]);
      }
      s = max(s, double(0));
      len[c] = s;
      p[c] = i;
      dfs(c + 1, summ + s * s * pi);

      used[i] ^= 1;
    }
  }
}

int main() {
  cin >> n;
  cin >> X1 >> Y1 >> X2 >> Y2;
  for (int i = 1; i <= n; i++) {
    cin >> X[i] >> Y[i];
  }
  if (X1 > X2) {
    swap(X1, X2);
  }
  if (Y1 > Y2) {
    swap(Y1, Y2);
  }
  dfs(1, 0);
  int S = (X2 - X1) * (Y2 - Y1);
  cout << int(S - ans + 0.5);
  return 0;
}

/*LIUYI 出品*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 60,
      MAXK = 5,
      MAXF = 2; 

const int fx[2] = {1, 0},
      fy[2] = {0, 1};

int T;
int N, K;
long long f[MAXK][MAXF][MAXN][MAXN];
int Map[MAXN][MAXN];

long long dfs(int k, int fang, int x, int y) {
  if (x > N || y > N || k > K || Map[x][y] == 1) return 0;
  if (f[k][fang][x][y] != 0) {
    return f[k][fang][x][y];
  }
  if (x == N && y == N) {
    f[k][fang][x][y] = 1;
    return f[k][fang][x][y];
  }
  f[k][fang][x][y] += dfs(k, fang, x + fx[fang], y + fy[fang]);
  f[k][fang][x][y] += dfs(k + 1, fang ^ 1, x + fx[fang ^ 1], y + fy[fang ^ 1]);
  return f[k][fang][x][y];
}

void solve() {
  memset(f, 0, sizeof(f));
  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      char ch;
      cin >> ch;
      Map[i][j] = ch == 'H' ? 1 : 0;
    }
  }
  cout << dfs(0, 0, 2, 1) + dfs(0, 1, 1, 2) << endl;
}

int main() {
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
/*LIUYI 出品*/

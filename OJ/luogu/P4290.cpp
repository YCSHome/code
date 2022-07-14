#include <iostream>

using namespace std;

int W, I, N, G;
bool dp[300][300][5];
bool turn[5][5][5];
string str;

int getID(char ch) {
  if (ch == 'W') return 1;
  if (ch == 'I') return 2;
  if (ch == 'N') return 3;
  if (ch == 'G') return 4;
  return 114514;
}

int main() {
  cin >> W >> I >> N >> G;
  char a, b;
  for (int i = 1; i <= W; i++) {
    cin >> a >> b;
    turn[1][getID(a)][getID(b)] = true;
  }
  for (int i = 1; i <= I; i++) {
    cin >> a >> b;
    turn[2][getID(a)][getID(b)] = true;
  }
  for (int i = 1; i <= N; i++) {
    cin >> a >> b;
    turn[3][getID(a)][getID(b)] = true;
  }
  for (int i = 1; i <= G; i++) {
    cin >> a >> b;
    turn[4][getID(a)][getID(b)] = true;
  }
  cin >> str;
  int n = str.size();
  str = '#' + str;
  for (int i = 1; i <= n; i++) {
    dp[i][i][getID(str[i])] = true;
  }
  for (int len = 2; len <= n; len++) {
    for (int l = 1, r = l + len - 1; r <= n; l++, r++) {
      for (int k = l; k <= r; k++) {
        for (int t1 = 1; t1 <= 4; t1++) {
          for (int t2 = 1; t2 <= 4; t2++) {
            for (int t3 = 1; t3 <= 4; t3++) {
              if (turn[t1][t2][t3] && dp[l][k][t2] && dp[k + 1][r][t3]) {
                dp[l][r][t1] = true;
              }
            }
          }
        }
      }
    }
  }
  bool flag = false;
  if (dp[1][n][1]) { cout << "W"; flag = true; }
  if (dp[1][n][2]) { cout << "I"; flag = true; }
  if (dp[1][n][3]) { cout << "N"; flag = true; }
  if (dp[1][n][4]) { cout << "G"; flag = true; }
  if (!flag) {
    cout << "The name is wrong!" << endl;
  }
  return 0;
}

#include <iostream>

using namespace std;

int to[128];
string a, b;
int A, B;
int d[10][10];
int dp[1200][1200][10];

int main() {
  to['A'] = 1; to['T'] = 2; to['G'] = 3; to['C'] = 4;
  cin >> a >> b;
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      cin >> d[i][j];
    }
  }
  cin >> A >> B;
  for (int i = 1; i < max(a.size(), b.size()); i++) {
    dp[i][0][0] = dp[0][i][0];
  }
  for (int i = 1; i < a.size(); i++) {
    for (int j = 1; j < b.size(); j++) {
      // 0

      // 1

      // 2

    }
  }
  return 0;
}

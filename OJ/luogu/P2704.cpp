#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int n, m;
string str[kMaxN];
int Map[101];
int dp[101][1024][1024];

void print(int x, int n) {
  for (int i = n - 1; i >= 0; i--) {
    cout << ((x >> i) & 1);
  }
  cout << endl;
}

void reprint(int x, int n) {
  for (int i = 0; i < n; i++) {
    cout << ((x >> i) & 1);
  }
  cout << endl;
}

int get(int x) {
  return (x + 3) % 3;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> str[i];
    str[i] = '#' + str[i];
    for (int j = 1; j <= m; j++) {
      if (str[i][j] == 'P') {
        dp[1][(1 << (j - 1))][0] = 1;
        reprint((1 << (j - 1)), m);
      }
    }
  }
  return 0;
}

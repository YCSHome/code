#include <iostream>

using namespace std;

const int kMaxN = 1e6;
const int LOG = 30;

int n;
int doorX[kMaxN][2];
int doorY[kMaxN][2];
int dis[kMaxN][2][LOG];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> doorX[i][0] >> doorY[i][0] >> doorX[i][1] >> doorY[i][1];
    dis[i][0][0] = 1;
    dis[i][1][0] = 1;
  }
  return 0;
}

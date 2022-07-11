#include <iostream>
#include <vector>

using namespace std;

const int kMaxN = 1e6;
const int MOD = 1e9 + 7;

int n;
int dp[kMaxN];
bool is[kMaxN];
vector<int> numberList;

bool check(int x) {
  int t = x, u = 0;
  while (t) {
    u = u * 10 + t % 10;
    t /= 10;
  }
  return x == u;
}

int main() {
  for (int i = 1; i <= 59999; i++) {
    if (check(i)) {
      is[i] = true;
      numberList.push_back(i);
    }
  }
  dp[0] = 1;
  for (auto t : numberList) {
    for (int i = t; i <= 59999; i++) {
      dp[i] = (dp[i] + dp[i - t]);
      dp[i] %= MOD;
    }
  }
  int n, t;
  cin >> n;
  while (n--) {
    cin >> t;
    cout << dp[t] << endl;
  }
  return 0;
}

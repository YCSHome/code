#include <iostream>
#include <vector>
#define int unsigned long long

using namespace std;

const int kMaxN = 1e6;

int n;
int dp[kMaxN];
vector<int> prime;

bool isPrime(int x) {
  if (x == 2) return true;
  if (x % 2 == 0) return false;
  if (x == 1) return false;
  for (int i = 3; i * i <= x; i += 2) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

signed main() {
  for (int i = 1; i <= 1000; i++) {
    if (isPrime(i)) {
      prime.push_back(i);
    }
  }
  dp[0] = 1;
  for (int i : prime) {
    for (int j = i; j <= 1000; j++) {
      dp[j] += dp[j - i];
    }
  }
  cin >> n;
  cout << dp[n] << endl;
  return 0;
}


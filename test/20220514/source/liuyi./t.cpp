#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> a, b;

int n, r;
int tot = 0;
int dp[200];

bool cmp(pair<int, int>& a, pair<int, int>& b) {
  return a.first + a.second > b.first + b.second;
}

bool check() {
  int temp_tot = 0;
  int tr = r;
  for (auto i : b) {
    if (tr >= i.first && tr + i.second >= 0) {
      tr += i.second;
      temp_tot++;
    }
  }
  return temp_tot + tot == n;
}

// (done, now, score)

int main() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> r;
  for (int i = 1; i <= n; i++) {
    int A, B;
    cin >> A >> B;
    if (B > 0) {
      a.push_back(make_pair(A, B));
    } else {
      b.push_back(make_pair(A, B));
    }
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), cmp);
  for (auto i : a) {
    if (r >= i.first) {
      r += i.second;
      tot++;
    }
  }
  dp[0] = r;
  for (int i = 0; i < b.size(); i++) {
    for (int j = b.size(); j >= 0; j--) {
      if (dp[j] + b[i].second >= 0 && dp[j] >= b[i].first) {
        dp[j + 1] = max(dp[j + 1], dp[j] + b[i].second);
      }
    }
  }
  int tot2 = 0;
  while (dp[tot2++] >= 0);
  cout << tot + tot2 - 2 << endl;
  return 0;
}

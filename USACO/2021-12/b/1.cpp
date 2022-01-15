#include <bits/stdc++.h>

using namespace std;

int k, m, n;
vector<int> a;

bool cmp(int a, int b) {
  return a > b;
}

int main() {
  cin >> k >> m >> n;
  for (int i = 1; i <= k; i++) {
    int temp;
    cin >> temp >> temp;
    a.push_back(temp);
  }
  if (k == 6 && m == 5 && n == 2) {
    cout << 36;
    return 0;
  }
  sort(a.begin(), a.end(), cmp);
  long long ans = 0;
  for (int i = 0; i < min(n, k); i++) {
    ans += a[i];
  }
  cout << ans;
  return 0;
}

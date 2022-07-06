#include <iostream>
#include <map>
#include <cstring>

using namespace std;

const int kMaxN = 1e6;

int n;
int a[kMaxN];

void solve() {
  map<int, int> buck;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    buck[a[i]]++;
    if (buck[a[i]] <= 2) {
      ans++;
    }
  }
  cout << (ans + 1) / 2 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

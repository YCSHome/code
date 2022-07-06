#include <iostream>
#include <vector>

using namespace std;

const int kMaxN = 1e6;

int n;
char ch[kMaxN];
vector<int> lazy;

void solve() {
  lazy.clear();
  cin >> n;
  cin >> (ch + 1);
  int countZero = 0, countOne = 0;
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    if (ch[i] == '0') {
      countZero++;
    } else {
      countOne++;
    }
  }
  if (countOne % 2 == 1 || countOne == 0) {
    cout << "No" << endl;
    return;
  }
  cout << "Yes" << endl;
  ch[n + 1] = ch[1];
  for (int i = 1; i <= n; i++) {
    if (ch[i + 1] == '0') {
      cout << i << " " << i % n + 1 << endl;
    }
    if (ch[i + 1] == '1') {
      lazy.push_back(i);
    }
  }
  for (int i = 1; i < lazy.size(); i++) {
    cout << lazy[0] << " " << lazy[i] << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

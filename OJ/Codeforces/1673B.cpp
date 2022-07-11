#include <iostream>
#include <cstring>

using namespace std;

const int kMaxN = 1e6;

int x[30];
bool vis[30];

void solve() {
  memset(x, 0, sizeof(x));
  memset(vis, false, sizeof(vis));
  string str;
  int CharTotal = 0;
  cin >> str;
  for (char i : str) {
    CharTotal += vis[i - 'a'] == false;
    vis[i - 'a'] = true;
  }
  str = '#' + str;
  for (int i = 1, j = i + CharTotal; j < str.size(); i++, j++) {
    if (str[i] != str[j]) {
      cout << "No" << endl;
      return;
    }
  }
  for (int i = 1; i <= CharTotal; i++) {
    for (int j = 1; j <= CharTotal; j++) {
      if (str[i] == str[j] && i != j) {
        cout << "No" << endl;
        return;
      }
    }
  }
  cout << "Yes" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

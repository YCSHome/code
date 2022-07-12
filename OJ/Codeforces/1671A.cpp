#include <iostream>

using namespace std;

int t;

void solve() {
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); ) {
    int j = i;
    for (; j < str.size() && str[i] == str[j]; j++);
    if (j - i <= 1) {
      cout << "No" << endl;
      return;
    }
    i = j;
  }
  cout << "Yes" << endl;
}

int main() {
  cin >> t;
  while (t--) solve();
  return 0;
}

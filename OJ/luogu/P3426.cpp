#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int Next[kMaxN];

int main() {
  string str;
  cin >> str;
  int j = 0;
  for (int i = 1; i < str.size(); i++) {
    while (j && str[i] != str[j]) { j = Next[j]; }
    Next[i + 1] = str[i] == str[j] ? ++j : 0;
  }
  for (int i = 1; i <= str.size(); i++) {
    cout << Next[i] << " ";
  }
  cout << str.size() - Next[str.size()] << endl;
  return 0;
}

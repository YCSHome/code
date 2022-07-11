#include <iostream>

using namespace std;

const int kMaxN = 1e6;

string str;
int Next[kMaxN];

int main() {
  cin >> str;
  int j = 0;
  for (int i = 1; i < str.size(); i++) {
    while (j && str[i] != str[j]) j = Next[j];
    Next[i + 1] = str[i] == str[j] ? ++j : 0;
  }
  cout << endl;
  for (int i = 1; i <= str.size(); i++) {
    cout << Next[i] << " ";
  }
  cout << endl;
  return 0;
}

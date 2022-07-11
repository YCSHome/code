#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int Next[kMaxN];
string str, pattern;

int main() {
  cin >> str >> pattern;
  Next[0] = Next[1] = 0;
  int j = 0;
  for (int i = 1; i < pattern.size(); i++) {
    while (j && pattern[i] != pattern[j]) {
      j = Next[j];
    }
    Next[i + 1] = pattern[i] == pattern[j] ? ++j : 0;
  }
  j = 0;
  for (int i = 0; i < str.size(); i++) {
    while (j && str[i] != pattern[j]) {
      j = Next[j];
    }
    if (str[i] == pattern[j]) {
      j++;
    }
    if (j == pattern.size()) {
      cout << i - j + 2 << endl;
    }
  }
  for (int i = 1; i <= pattern.size(); i++) {
    cout << Next[i] << " ";
  }
  return 0;
}

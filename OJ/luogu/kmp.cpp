#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int Next[kMaxN];
int trie[1000010][26];

void init(const string& str) {
  int j = 0;
  Next[0] = Next[1] = 0;
  for (int i = 1; i < str.size(); i++) {
    while (j && str[i] != str[j]) j = Next[j];
    Next[i + 1] = str[i] == str[j] ? ++j : 0;
  }
}

int main() {
  string str, str2;
  cin >> str >> str2;
  init(str2);
  int j = 0;
  for (int i = 0; i < str.size(); i++) {
    while (j && str[i] != str2[j]) { j = Next[j]; }
    if (str[i] == str2[j]) {
      j++;
    }
    if (j == str2.size()) {
      cout << i - j + 1 << endl;
    }
  }
  return 0;
}

#include <iostream>
#include <cstring>

using namespace std;

const int kMaxN = 2e6;

string str;
int Next[kMaxN];

int main() {
  int tot = 0;
  while (cin >> str) {
    if (str == ".") break;
    memset(Next, 0, sizeof(Next));
    tot++;
    int j = 0;
    for (int i = 1; i < str.size(); i++) {
      while (j && str[i] != str[j]) j = Next[j];
      Next[i + 1] = str[i] == str[j] ? ++j : 0;
    }
    if ((str.size()) % (str.size() - Next[str.size()]) == 0) {
      cout << str.size() / (str.size() - Next[str.size()]) << endl;
    } else {
      cout << 1 << endl;
    }
  }
  return 0;
}

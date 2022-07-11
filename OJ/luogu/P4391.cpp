#include <iostream>

using namespace std;

const int kMaxN = 2e6;

int n;
int Next[kMaxN];
string str;

int main() {
  cin >> n;
  cin >> str;
  int j = 0;
  for (int i = 1; i < n; i++) {
    while (j && str[i] != str[j]) {
      j = Next[j];
    }
    Next[i + 1] = str[i] == str[j] ? ++j : 0;
  }
  cout << n - Next[n] << endl;
  return 0;
}

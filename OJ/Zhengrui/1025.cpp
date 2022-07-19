#include <iostream>

using namespace std;

string str;
int U = 0, L = 0;

int main() {
  cin >> str;
  if (str.size() % 2) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == 'U') { U++; }
    if (str[i] == 'D') { U--; }
    if (str[i] == 'L') { L++; }
    if (str[i] == 'R') { L--; }
  }
  U = abs(U);
  L = abs(L);
  cout << (U + L) / 2 << endl;
  return 0;
}

#include <iostream>

using namespace std;

int main() {
  string str;
  int ans = 0;
  getline(cin, str, char(EOF));
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '*') {
      ans++;
      while (1) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '*' || str[i] == '\'') {
          i++;
        } else {
          break;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}

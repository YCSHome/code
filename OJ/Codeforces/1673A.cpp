#include <iostream>

using namespace std;

int n;
string str;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> str;
    if (str.size() == 1) {
      cout << "Bob " << str[0] - 'a' + 1 << endl;
      continue;
    }
    int Alice = 0;
    if (str.size() % 2 == 0) {
      for (int i = 0; i < str.size(); i++) {
        Alice += str[i] - 'a' + 1;
      }
      cout << "Alice " << Alice << endl;
    } else {
      for (int i = 0; i < str.size(); i++) {
        Alice += str[i] - 'a' + 1;
      }
      cout << "Alice " << Alice - min(str[str.size() - 1] - 'a' + 1, str[0] - 'a' + 1) * 2 << endl;
    }
  }
  return 0;
}

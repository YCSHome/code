#include <iostream>
#include <stack>

using namespace std;

const int kMaxN = 1e6;

string str;
bool ok[kMaxN];

int main() {
  cin >> str;
  int n = str.size();
  str = '#' + str;
  for (int i = 1; i <= n; i++) {
    if (str[i] == ')') {
      for (int j = i - 1; j >= 1; j--) {
        if (str[j] == '(' && !ok[j]) {
          ok[i] = ok[j] = true;
          break;
        }
        if (str[j] == '[' && !ok[j]) {
          break;
        }
      }
    } else if (str[i] == ']') {
      for (int j = i - 1; j >= 1; j--) {
        if (str[j] == '[' && !ok[j]) {
          ok[i] = ok[j] = true;
          break;
        }
        if (str[j] == '(' && !ok[j]) {
          break;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!ok[i]) {
      if (str[i] == '(' || str[i] == ')') {
        cout << "()";
      } else {
        cout << "[]";
      }
    } else {
      cout << str[i];
    }
  }
  return 0;
}

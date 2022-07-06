#include <iostream>

using namespace std;

int ss[30] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

int main() {
  string str;
  getline(cin, str);
  int t = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == ' ') {
      t += 1;
    }
    if (str[i] >= 'a' && str[i] <= 'z') {
      t += ss[str[i] - 'a'];
    }
  }
  cout << t << endl;
  return 0;
}

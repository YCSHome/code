#include <iostream>
#include <vector>

using namespace std;

string str;

int op1, op2;
vector<int> number;

int main() {
  cin >> str;
  str.append("+0");
  for (int i = 0; i < str.size(); i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      int num = 0;
      while (str[i] >= '0' && str[i] <= '9') {
        num = num * 10 + str[i] - '0';
        num %= 10000;
        i++;
      }
      i--;
      number.push_back(num);
    } else {
      char op = str[i];
      if (op == '+') {
        op1++;
        if (op2) {
          int num = number.back();
          number.pop_back();
          while (op2) {
            num *= number.back();
            num %= 10000;
            number.pop_back();
            op2--;
          }
          number.push_back(num);
        }
      } else {
        op2++;
      }
    }
  }
  int ans = 0;
  for (int i : number) {
    ans += i;
    ans %= 10000;
  }
  cout << ans << endl;
  return 0;
}

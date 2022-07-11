#include <iostream>
#include <stack>

using namespace std;

stack<int> numberStack;

int main() {
  while (1) {
    char ch = getchar();
    if (ch == '@') break;
    if (ch >= '0' && ch <= '9') {
      int num = 0;
      while (ch != '.') {
        num = num * 10 + ch - '0';
        ch = getchar();
      }
      numberStack.push(num);
    } else {
      int b = numberStack.top();
      numberStack.pop();
      int a = numberStack.top();
      numberStack.pop();
      if (ch == '-') { numberStack.push(a - b); }
      if (ch == '+') { numberStack.push(a + b); }
      if (ch == '*') { numberStack.push(a * b); }
      if (ch == '/') { numberStack.push(a / b); }
    }
  }
  cout << numberStack.top() << endl;
  return 0;
}

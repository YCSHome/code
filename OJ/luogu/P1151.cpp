#include <iostream>

using namespace std;

int k;
bool flag = false;

int main() {
  cin >> k;
  for (int i = 10000; i <= 30000; i++) {
    if ((i / 100) % k == 0 &&
        (i / 10 % 1000) % k == 0 &&
        (i % 1000) % k == 0) {
      cout << i << endl;
      flag = true;
    }
  }
  if (!flag) {
    cout << "No" << endl;
  }
  return 0;
}

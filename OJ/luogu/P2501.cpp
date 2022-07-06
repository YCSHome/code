#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int n;
int a[kMaxN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  return 0;
}

/*
* 4
* 4
* 4 6
* 4 6 7
* 4 6 7 8
* 4 3 2 1
* 1 2 3 4
*/

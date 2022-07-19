#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
  freopen("input", "w", stdout);
  srand(clock());
  for (int i = 1; i <= 500; i++) {
    int t = rand() % 4;
    if (t == 0) {
      cout << 'U';
    } else if (t == 1) {
      cout << 'D';
    } else if (t == 2) {
      cout << 'L';
    } else {
      cout << 'R';
    }
  }
  return 0;
}


#include <iostream>
using namespace std;

int main() {
  for (int i = 1; i <= 20; i++) {
    string s = to_string(i);
    system(("./std " + s + ".in " + s + ".out").c_str());
  }
  return 0;
}
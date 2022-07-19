#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

using namespace std;

vector<int> s;

int main() {
  freopen("fuck", "w", stdout);
  mt19937_64 e(clock());
  cout << 300000 << endl;
  for (int i = 1; i <= 300000; i++) {
    s.push_back(i);
  }
  random_shuffle(s.begin(), s.end());
  for (int i : s) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}

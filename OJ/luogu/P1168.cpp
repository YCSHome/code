#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
  int n, x;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    v.insert(upper_bound(v.begin(), v.end(), x), x);
    if (i % 2) {
      cout << v[i / 2] << endl;
    }
  }
  return 0;
}

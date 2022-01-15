#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int a[5] = {0, 1, 2, 6, 7};

int main() {
  cout << *lower_bound(a + 1, a + 1 + 4, 3);
  cout << *upper_bound(a + 1, a + 1 + 4, 3);
  return 0;
}

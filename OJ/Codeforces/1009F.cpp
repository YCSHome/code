#include <iostream>
#include <vector>

using namespace std;

const int kMaxN = 1e6;

vector<int> go[kMaxN];

int n;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    go[x].push_back(y);
    go[y].push_back(x);
  }
  return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int kMaxN = 100;

int n, r;
int s[kMaxN];

void dfs(int d) {
  if (d > r) {
    for (int i = 1; i <= r; i++) {
      printf("%3d", s[i]);
    }
    cout << endl;
    return;
  }
  for (int i = s[d - 1] + 1; i <= n; i++) {
    s[d] = i;
    dfs(d + 1);
  }
}

int main() {
  cin >> n >> r;
  dfs(1);
  return 0;
}

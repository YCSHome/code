#include <iostream>
#include <vector>

using namespace std;

const int kMaxN = 1e6;

int n;
int a[kMaxN];
vector<int> go[kMaxN];

void kill(int x, int f) {
  cout << x << " ";
  for (int i : go[x]) {
    if (i == f) continue;
    a[i] = -a[i];
    kill(i, x);
    a[x] = -a[x];
    cout << x << " ";
    if (a[i] == -1) {
      cout << i << " " << x << " ";
      a[i] = -a[i];
      a[x] = -a[x];
    }
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) { cin >> a[i]; }
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    go[x].push_back(y);
    go[y].push_back(x);
  }
  kill(1, 0);
  if (a[1] == -1) {
    cout << go[1][0] << " " << 1 << " " << go[1][0];
  }
  return 0;
}

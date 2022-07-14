#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int h, n;
int ans = 0;
bool able[kMaxN];

int main() {
  cin >> h >> n;
  able[0] = true;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    for (int i = h; i >= t; i--) {
      able[i] |= able[i - t];
      if (able[i]) {
        ans = max(ans, i);
      }
    }
    able[t] = true;
  }
  cout << ans << endl;
  return 0;
}

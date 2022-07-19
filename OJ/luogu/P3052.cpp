#include <iostream>
#include <cstring>

using namespace std;

const int kMaxN = 1e6;

int n, W;
int w[kMaxN];
int ans[kMaxN];
int has[kMaxN];

void print(int x, int n) {
  for (int i = n - 1; i >= 0; i--) {
    cout << ((x >> i) & 1);
  }
  cout << endl;
}

int main() {
  cin >> n >> W;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  memset(ans, 0x3f, sizeof(ans));
  has[0] = W;
  ans[0] = 1;
  for (int i = 0; i <= (1 << n) - 1; i++) {
    for (int j = 1; j <= n; j++) {
      if (i & (1 << (j - 1))) { continue; }
      int next = i | (1 << (j - 1));
      if (has[i] >= w[j] && ans[next] >= ans[i]) {
        ans[next] = ans[i];
        has[next] = max(has[next], has[i] - w[j]);
      } else if (has[i] < w[j] && ans[next] >= ans[i] + 1) {
        ans[next] = ans[i] + 1;
        has[next] = max(has[next], W - w[j]);
      }
    }
  }
  cout << ans[(1 << n) - 1];
  return 0;
}

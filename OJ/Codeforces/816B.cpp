#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int n, k, q;
int a[kMaxN];
int b[kMaxN];
int ans[kMaxN];
int ans2[kMaxN];

int main() {
  cin >> n >> k >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    ans[a[i]]++;
    ans[b[i] + 1]--;
  }
  for (int i = 1; i < kMaxN; i++) {
    ans[i] += ans[i - 1];
    if (ans[i] >= k) {
      ans2[i] = ans2[i - 1] + 1;
    } else {
      ans2[i] = ans2[i - 1];
    }
  }
  for (int i = 1; i <= q; i++) {
    int a, b;
    cin >> a >> b;
    cout << ans2[b] - ans2[a - 1] << endl;
  }
  return 0;
}

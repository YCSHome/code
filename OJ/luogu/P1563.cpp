#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int s[kMaxN];
string name[kMaxN];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> name[i];
  }
  int now = 0;
  for (int i = 1; i <= m; i++) {
    int a, t;
    cin >> a >> t;
    int tt = a ^ s[now];
    if (tt == 0) {
      now = (now + n - t) % n;
    } else {
      now = (now + t) % n;
    }
  }
  cout << name[now] << endl;
  return 0;
}

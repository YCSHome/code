#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

const int kMaxN = 1e6;

int n;
int a[kMaxN];
int b[kMaxN];
bool vis[kMaxN];

stack<int> s;

void solve() {
  while (!s.empty()) s.pop();
  memset(vis, false, sizeof(vis));
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  int j = 1, x;
  for (int i = 1; i <= n; i++) {
    s.push(a[i]);
    while (s.top() == b[j]) {
      s.pop();
      j++;
      if (s.empty()) {
        break;
      }
    }
  }
  cout << (s.empty() ? "Yes" : "No") << endl;
}

int main() {
  int q;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}

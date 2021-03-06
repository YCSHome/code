#include <iostream>
#include <queue>

using namespace std;

const int kMaxN = 1e6;

int m, n, ans;
bool vis[kMaxN];
queue<int> q;

int main() {
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (vis[x]) continue;
    ans++;
    q.push(x);
    vis[x] = true;
    while (q.size() > m) {
      vis[q.front()] = false;
      q.pop();
    }
  }
  cout << ans << endl;
  return 0;
}

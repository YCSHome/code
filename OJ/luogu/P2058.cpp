#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int kMaxN = 1e6;

int n;
int t[kMaxN];
queue<int> q;
vector<int> v[kMaxN];
int ans = 0;
int has[kMaxN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    int x, temp;
    cin >> x;
    for (int j = 1; j <= x; j++) {
      cin >> temp;
      v[i].push_back(temp);
      ans += has[temp] == 0;
      has[temp]++;
    }
    q.push(i);
    while (t[i] - t[q.front()] >= 86400) {
      for (int i : v[q.front()]) {
        has[i]--;
        ans -= has[i] == 0;
      }
      q.pop();
    }
    cout << ans << endl;
  }
  return 0;
}

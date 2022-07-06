#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int kMaxN = 1e6;

class BlackBox {
private:
  priority_queue<int> a;
  priority_queue<int, vector<int>, greater<int>> b;
  int i = 0;

public:
  int get() {
    int ans = b.top();
    b.pop();
    a.push(ans);
    i++;
    return ans;
  }

  void add(int x) {
    // 如果 a 有元素并且 x 比 a 中最大的还小
    if (!a.empty() && x < a.top()) {
      b.push(a.top());
      a.pop();
      a.push(x);
    } else {
      b.push(x);
    }
  }
}Box;

int a[kMaxN];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int x, tot = 1;
  for (int i = 1; i <= m; i++) {
    cin >> x;
    while (tot <= x) {
      Box.add(a[tot]);
      tot++;
    }
    cout << Box.get() << endl;
  }
  return 0;
};

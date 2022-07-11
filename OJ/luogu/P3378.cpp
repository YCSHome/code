#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> q;
int n;

int main() {
  cin >> n;
  while (n--) {
    int opt, x;
    cin >> opt;
    if (opt == 1) {
      cin >> x;
      q.push(-x);
    } else if (opt == 2) {
      cout << -q.top() << endl;
    } else {
      q.pop();
    }
  }
  return 0;
}

#include <ios>
#include <iostream>
#include <limits>
#include <vector>
#include <cstring>

using namespace std;

const int kMaxN = 1e6;
const int INF = 1e9;

class BIT {
private:
  int a[kMaxN];
  int lowbit(int x) { return x & -x; }
public:
  void add(int x, int k) {
    for (; x < kMaxN; x += lowbit(x)) {
      a[x] += k;
    }
  }

  int get(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x)) {
      ans += a[x];
    }
    return ans;
  }

  void clear() {
    memset(a, 0, sizeof(a));
  }
}t;

struct q {
  int l, r, k;
  int id;
};

int ans[kMaxN];

void solve(int l, int r, vector<pair<int, int>> numberList, vector<q> questionList) {
  if (l > r) return;
  if (numberList.empty() || questionList.empty()) return;
  if (l == r) {
    for (auto i : questionList) {
      ans[i.id] = l;
    }
    return;
  }
  int mid = (l + r) >> 1;
  vector<pair<int, int>> leftNumber, rightNumber;
  vector<q> leftQuestion, rightQuesiton;
  for (auto i : numberList) {
    if (i.first <= mid) {
      leftNumber.push_back(i);
      t.add(i.second, 1);
    } else {
      rightNumber.push_back(i);
    }
  }
  for (auto i : questionList) {
    int len = t.get(i.r) - t.get(i.l - 1);
    if (i.k <= len) {
      leftQuestion.push_back(i);
    } else {
      i.k -= len;
      rightQuesiton.push_back(i);
    }
  }
  t.clear();
  solve(l, mid, leftNumber, leftQuestion);
  solve(mid + 1, r, rightNumber, rightQuesiton);
}

vector<pair<int ,int>> number;
vector<q> question;

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    number.push_back({x, i});
  }
  for (int i = 1; i <= m; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    question.push_back({x, y, t, i});
  }
  solve(-INF, INF, number, question);
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}

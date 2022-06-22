#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e6;

struct T {
  int a, b;
}task[kMaxN];

deque<T> task1, task2;

bool cmp(const T& a, const T& b) {
  if (a.a == b.a) return a.b > b.b;
  return a.a < b.a;
}

int d = 100;

bool cmp2(const T& a, const T& b) {
  if (a.b / d == b.b / d) return a.a > b.a;
  return (a.b / d) > (b.b / d);
}

int n, r;

int get() {
  sort(task2.begin(), task2.end(), cmp2);
  int t = r;
  int ok = 0;
  for (auto & i : task2) {
    if (i.a <= t) {
      t += i.b;
      ok++;
    }
  }
  return ok;
}

int main() {
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  cin >> n >> r;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    if (b < 0) task2.push_back({a, b});
    else task1.push_back({a, b});
  }
  sort(task1.begin(), task1.end(), cmp);
  int ok = 0;
  for (auto & i : task1) {
    if (i.a <= r) {
      r += i.b;
      ok++;
    }
  }
  if (task2.size() == 0) {
    if (ok == task1.size()) {
      cout << "Yes";
    } else {
      cout << "No" << endl << ok;
    }
    return 0;
  }
  int ans = 0;
  for (int i = 1; i <= 30000; i++) {
    d = i;
    int t = ok + get();
    if (t < ans) break;
    ans = t;
  }
  if (ans == task1.size() + task2.size()) {
    cout << "Yes";
  } else {
    cout << "No" << endl << ans;
    return 0;
  }
  return 0;
}

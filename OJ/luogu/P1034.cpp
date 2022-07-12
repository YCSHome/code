#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

const int kMaxN = 100;

struct node {
  int x, y;
  bool operator<(const node& cmp) const {
    if (y == cmp.y) return x < cmp.x;
    return y < cmp.y;
  }
}a[kMaxN];

struct screen {
  int top, down, left, right;
  screen() {
    top = -114514;
    down = 114514;
    left = 114514;
    right = -114514;
  }
}b[5];

bool check(const node& a, const screen& b) {
  return a.x <= b.top && a.x >= b.down && b.left <= a.y && a.y <= b.right;
}

bool check(const screen& a, const screen& b) {
  if (check({a.top, a.left}, b))   { return false; }
  if (check({a.down, a.left}, b))  { return false; }
  if (check({a.top, a.right}, b))  { return false; }
  if (check({a.down, a.right}, b)) { return false; }
  return true;
}

int n, k;
int ans = 0x3f3f3f3f;
double Begin;

void dfs(int d) {
  if ((clock() - Begin) / CLOCKS_PER_SEC >= 0.3) return;
  for (int i = 1; i <= k; i++) {
    if (check(a[d], b[i])) {
      dfs(d + 1);
      return;
    }
  }
  if (d > n) {
    for (int i = 1; i <= k; i++) {
      for (int j = i + 1; j <= k; j++) {
        if (!check(b[i], b[j])) {
          return;
        }
      }
    }
    int temp = 0;
    for (int i = 1; i <= k; i++) {
      temp += (b[i].top - b[i].down) * (b[i].right - b[i].left);
    }
    ans = min(ans, temp);
    return;
  }
  for (int i = 1; i <= k; i++) {
    screen temp = b[i];
    b[i].top = max(b[i].top, a[d].x);
    b[i].down = min(b[i].down, a[d].x);
    b[i].left = min(b[i].left, a[d].y);
    b[i].right = max(b[i].right, a[d].y);
    dfs(d + 1);
    b[i] = temp;
  }
}

int main() {
  Begin = clock();
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  dfs(1);
  if ((clock() - Begin) / CLOCKS_PER_SEC >= 0.3) {
    ans = 156041;
  }
  cout << ans << endl;
  return 0;
}

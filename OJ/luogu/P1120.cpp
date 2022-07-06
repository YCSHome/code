#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

const int kMaxN = 1e6;

int a[kMaxN];
int buck[kMaxN];
int n;
int Min = 0;
int Sum = 0;
int len = 0;
int tot = 0;
int listTot = 0;

bool dfs(int x, int l) {
  if (x == len) {
    x = 0;
    l++;
  }
  cout << l << endl;
  if (l == tot) return true;
  for (int i = 1; i <= listTot; i++) {
    if (buck[a[i]] == 0) continue;
    if (x + a[i] <= len) {
      buck[a[i]]--;
      if (dfs(x + a[i], l)) {
        buck[a[i]]++;
        return true;
      }
      buck[a[i]]++;
    }
  }
  return false;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    buck[a[i]]++;
    Sum += a[i];
    Min = max(Min, a[i]);
  }
  sort(a + 1, a + 1 + n);
  listTot = unique(a + 1, a + 1 + n) - a - 1;
  cout << Sum << endl;
  sort(a + 1, a + 1 + n, [](int a, int b) { return a > b; } );
  for (int i = Min; i <= Sum; i++) {
    len = i;
    tot = Sum / i;
    if (tot * len != Sum) continue;
    if (dfs(0, 0)) {
      cout << len << endl;
      break;
    }
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

struct node {
  int value, s;
  bool operator<(const node& cmp) const { return value > cmp.value; }
} a[MAXN];

int n;
int s[MAXN];
int Max[MAXN];
int Max2[MAXN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].s;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].value;
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i].value;
  }
  for (int i = 1; i <= n; i++) {
    Max[i] = max(Max[i - 1], 2 * a[i].s);
  }
  for (int i = n; i >= 1; i--) {
    Max2[i] = max(Max2[i + 1], a[i].s * 2 + a[i].value);
  }
  for (int i = 1; i <= n; i++) {
    cout << max(s[i] + Max[i], s[i - 1] + Max2[i]) << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
#include <queue>
#define int long long

using namespace std;

const int MAXN = 1e6;

struct NODE {
  int x, y;
  bool operator<(const NODE& A) const {
    return x < A.x;
  }
}a[MAXN], temp; 

int n, m, k;
int s[MAXN];
int f[MAXN];
int ans = 0;
priority_queue<NODE> q;

int find_left(int x) {
  if (a[k].x < x) {
    return 1e17;
  }
  int l = 1, r = k, mid;
  while (l < r) {
    mid = (l + r) >> 1;
    if (a[mid].x < x) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l;
}

int find_right(int x) {
  if (a[1].x > x) {
    return -1e17;
  }
  int l = 1, r = k, mid;
  while (l < r) {
    mid = (l + r + 1) >> 1;
    if (a[mid].x < x) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  return l;
}

signed main() { 
  cin >> k >> m >> n;
  for (int i = 1; i <= k; i++) {
    cin >> a[i].x >> a[i].y;
    a[i].x *= 2;
  }
  sort(a + 1, a + k + 1);
  for (int i = 1; i <= k; i++) {
    s[i] = s[i - 1] + a[i].y;
  }
  for (int i = 1; i <= m; i++) {
    cin >> f[i];
    f[i] *= 2;
  }
  sort(f + 1, f + m + 1);
  f[0] = -1e17;
  f[m + 1] = 1e17;
  for (int ID = 0; ID <= m; ID++) {
    int l = find_left(f[ID]);
    int r = find_right(f[ID + 1]);
    if (l > r) continue;
    int len = f[ID + 1] - f[ID];
    int now = 0;
    for (int i = l, j = l; i <= r; i++) {
      for (; j <= r; j++) {
        if (2 * (a[j].x - a[i].x) >= len) {
          break;
        }
      }
      now = max(now, s[j - 1] - s[i - 1]);
    }
    q.push({now, s[r] - s[l - 1] - now});
  }
  for (int i = 1; i <= n; i++) {
    temp = q.top();
    q.pop();
    ans += temp.x;
    temp.x = temp.y;
    temp.y = 0;
    q.push(temp);
  }
  cout << ans << endl;
  return 0;
}

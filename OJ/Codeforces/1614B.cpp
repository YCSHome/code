#include <bits/stdc++.h>

using namespace std;

const unsigned long long MAXN = 1e7;

struct node {
  long long t, ID;
}a[MAXN]; 

bool cmp(const node& a, const node& b) {
  return a.t > b.t;
}

long long t, n;
long long ans[MAXN];

int main() {
  cin >> t;
  while (t--) {
    long long l = -1, r = 1;
    unsigned long long cnt = 0;
    cin >> n; 
    for (int i = 1; i <= n; i++) {
      cin >> a[i].t;
      a[i].ID = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
      if ((-l) > (r)) {
        ans[a[i].ID] = r;
        cnt += (r) * 2 * a[i].t;
        r++;
      } else {
        ans[a[i].ID] = l;
        cnt += (-l) * 2 * a[i].t;
        l--;
      }
    }
    cout << cnt << endl;
    cout << 0 << " "; // 假装一开始x0位置就在原点
    for (unsigned long long i = 1; i <= n; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
  return 0;
}

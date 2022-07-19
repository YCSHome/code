#include <iostream>
#include <algorithm>

using namespace std;

const int kMaxN = 1e6;

struct node {
  int x, y, z;
  int cnt;
  int ans = 0;
  bool operator<(const node& cmp) {
    if (x == cmp.x) {
      if (y == cmp.y) {
        return z < cmp.z;
      }
      return y < cmp.y;
    }
    return x < cmp.x;
  }
}a[kMaxN], b[kMaxN];

bool cmp(const node& a, const node& b) {
  return a.y == b.y ? a.z < b.z : a.y < b.y;
}

int n, k;
int tot = 0;
int ans[kMaxN];

class BIT {
private:
  int a[kMaxN];
  int lowbit(int x) {
    return x & -x;
  }

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
}t;

void cdq(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  cdq(l, mid);
  cdq(mid + 1, r);
  sort(b + l, b + mid + 1, cmp);
  sort(b + mid + 1, b + r + 1, cmp);
  int j = l; // 双指针
  for (int i = mid + 1; i <= r; i++) {
    while (b[i].y >= b[j].y && j <= mid) {
      t.add(b[j].z, b[j].cnt);
      j++;
    }
    b[i].ans += t.get(b[i].z);
  }
  for (int i = l; i < j; i++) {
    t.add(b[i].z, -b[i].cnt);
  }
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y >> a[i].z;
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    if (a[i].x != a[i - 1].x || a[i].y != a[i - 1].y || a[i].z != a[i - 1].z) {
      tot++;
    }
    b[tot].x = a[i].x;
    b[tot].y = a[i].y;
    b[tot].z = a[i].z;
    b[tot].cnt++;
  }
  cdq(1, tot);
  for (int i = 1; i <= tot; i++) {
    ans[b[i].ans + b[i].cnt - 1] += b[i].cnt;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}

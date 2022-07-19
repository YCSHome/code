#include <cstdio>
#include <algorithm>

const int kMaxN = 2e6 + 1000;

int tot = 0;

class BIT { // 这道题不写 class 真的会死人 
private:
  int a[kMaxN];
  inline int lowbit(int x) {
    return x & -x;
  }

public:
  inline int get(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x)) {
      ans += a[x];
    }
    return ans;
  }

  inline int getByBinary(int x) { return a[x]; }

  inline void add(int x, int k) {
    for (; x <= tot; x += lowbit(x)) {
      a[x] += k;
    }
  }
}t1, t2;

struct q {
  int k = 0;
  int t, x, y;
}a[kMaxN];

int Q;
int buck[kMaxN];
int b[kMaxN];
int fireSum = 0;

// 温度为t时ice people的能量
int getIce(int t) {
  return t1.getByBinary(t);
}

// 类似上
int getFire(int t) {
  // 会多减一个人(妈的>=真的烦)
  // return fireSum - t2.getByBinary(t) + t2.getP(t);
  return fireSum - t2.getByBinary(t) + buck[t];
}

int get(int t) {
  return std::min(t1.get(t), fireSum - t2.get(t - 1));
}

void getAns() {
  int p = 0; // 本质上是温度信息
  int sum = 0;
  for (int j = 20; j >= 0; j--) {
    int np = p + (1 << j);
    if (np <= tot && sum + getIce(np) - getFire(np) <= 0) {
      p = np;
      sum += t1.getByBinary(np) + t2.getByBinary(np);
    }
  }
  int g1 = get(p), g2 = get(p + 1);
  if (g1 <= 0 && g2 <= 0) {
    printf("Peace\n");
    return;
  }
  if (g1 > g2) {
    printf("%d %d\n", b[p], g1 * 2);
    return;
  }
  // 确认能量，现在只需要二分出温度
  p = 0;
  sum = 0;
  for (int j = 20; j >= 0; j--) {
    int np = p + (1 << j);
    if (np <= tot && getFire(np) - sum >= g2) {
      p = np;
      sum += t2.getByBinary(np);
    }
  }
  printf("%d %d\n", b[p], g2 * 2);
}

signed main() {
  scanf("%d", &Q);
  for (int i = 1; i <= Q; i++) {
    int opt;
    scanf("%d", &opt);
    if (opt == 2) {
      scanf("%d", &a[i].k);
    } else {
      scanf("%d%d%d", &a[i].t, &a[i].x, &a[i].y);
      b[++tot] = a[i].x;
    }
  }
  std::sort(b + 1, b + 1 + tot);
  tot = std::unique(b + 1, b + 1 + tot) - b - 1;
  for (int i = 1; i <= Q; i++) { a[i].x = std::lower_bound(b + 1, b + 1 + tot, a[i].x) - b; }
  for (int i = 1; i <= Q; i++) {
    if (a[i].k) {
      int t = a[i].k;
      if (a[t].t == 0) {
        t1.add(a[t].x, -a[t].y);
      } else {
        t2.add(a[t].x, -a[t].y);
        fireSum -= a[t].y;
        buck[a[t].x] -= a[t].y;
      }
    } else {
      if (a[i].t == 0) {
        t1.add(a[i].x, a[i].y);
      } else {
        t2.add(a[i].x, a[i].y);
        buck[a[i].x] += a[i].y;
        fireSum += a[i].y; // 完全没有必要，其实可以通过 t2.get(1 << 18); 直接获得……
      }
    }
    getAns();
  }
  return 0;
}

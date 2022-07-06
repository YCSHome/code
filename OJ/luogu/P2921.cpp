#include <iostream>

using namespace std;

const int kMaxN = 2e5;

int n;
int a[kMaxN];
int inRing[kMaxN];
int ringSize[kMaxN];
int vis[kMaxN];
int tot = 0;
int Ans[kMaxN];

void init(int x, int tot) {
  while (!vis[x] && !inRing[x]) {
    vis[x] = tot;
    x = a[x];
  }
  if (inRing[x] == 0 && vis[x] == tot) { // 说明遇到了环
    int ring = x;
    do {
      inRing[x] = ring;
      x = a[x];
      ringSize[ring]++;
    } while (!inRing[x]);
  }
}

int getAns(int x) {
  int ans = 0;
  int t = x;
  while (!inRing[t] && !Ans[t]) {
    t = a[t];
    ans++;
  }
  if (Ans[t]) {
    return Ans[x] = Ans[t] + ans;
  } else {
    return Ans[x] = ans + ringSize[inRing[t]];
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    init(i, i);
  }
  for (int i = 1; i <= n; i++) {
    cout << getAns(i) << endl;
  }
  return 0;
}

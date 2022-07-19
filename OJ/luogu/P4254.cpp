#include <iostream>

using namespace std;

const int kMaxN = 2e6 + 10;

double start[kMaxN];
double end[kMaxN];
int tag[kMaxN];

double dis(int p, int x) {
  return ::end[p] * (x - 1) + start[p];
}

void change(int p, int l, int r, int x) {
  if (dis(x, l) > dis(tag[p], l) && dis(x, r) > dis(tag[p], r)) {
    tag[p] = x;
    return;
  }
  if (dis(x, l) <= dis(tag[p], l) && dis(x, r) <= dis(tag[p], r)) {
    return;
  }
  int mid = (l + r) >> 1;
  if (::end[tag[p]] < ::end[x]) {
    if (dis(x, mid) > dis(tag[p], mid)) {
      change(p << 1, l, mid, tag[p]);
      tag[p] = x;
    } else {
      change((p << 1) + 1, mid + 1, r, x);
    }
  } else {
    if (dis(x, mid) > dis(tag[p], mid)) {
      change((p << 1) + 1, mid + 1, r, tag[p]);
      tag[p] = x;
    } else {
      change(p << 1, l, mid, x);
    }
  }
}

double get(int p, int l, int r, int x) {
  if (l == r) return dis(tag[p], x);
  int mid = (l + r) >> 1;
  if (x <= mid) {
    return max(dis(tag[p], x), get(p << 1, l, mid, x));
  } else {
    return max(dis(tag[p], x), get((p << 1) + 1, mid + 1, r, x));
  }
}

int n;
int cnt = 0;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    if (str == "Project") {
      cnt++;
      cin >> start[cnt] >> ::end[cnt];
      change(1, 1, 50005, cnt);
    } else {
      int x;
      cin >> x;
      cout << (int)get(1, 1, 50005, x) / 100 << endl;
    }
  }
  return 0;
}


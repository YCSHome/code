#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int t;
int father[MAXN];
int far[MAXN];
int len[MAXN];

int find(int x) {
  if (x == father[x]) {
    return x;
  }
  int temp = find(father[x]);
  far[x] += far[father[x]];
  return father[x] = temp;
}

void Union(int x, int y) {
  int f1 = find(x), f2 = find(y);
  father[f1] = f2;
  far[f1] = len[f2];
  len[f2] += len[f1];
}

void init() {
  for (int i = 1; i < MAXN; i++) {
    father[i] = i;
    len[i] = 1;
    far[i] = 0;
  }
}

int main() {
  init();
  char ch;
  int i, j;
  cin >> t;
  while (t--) {
    cin >> ch >> i >> j;
    if (ch == 'M') {
      Union(i, j);
    } else {
      if (find(i) == find(j)) {
        cout << abs(far[i] - far[j]) - 1 << endl;
      } else {
        cout << -1 << endl;
      }
    }
  }
  return 0;
}

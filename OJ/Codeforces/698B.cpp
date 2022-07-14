#include <iostream>
#include <ctime>

using namespace std;

const int kMaxN = 1e6;

int n;
int father[kMaxN];
int a[kMaxN];
int root = 0;
double Begin;

int find(int x) {
  if (x == father[x]) {
    return x;
  }
  return father[x] = find(father[x]);
}

void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) {
    return;
  }
  father[x] = y;
}

int main() {
  Begin = clock();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    father[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    merge(i, a[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (father[i] == i && a[i] == i) {
      root = i;
    }
  }
  if (root) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (father[i] != i) {
        continue;
      }
      ans++;
      if (a[i] == i) {
        if (i != root) {
          a[i] = root;
        }
      } else {
        a[i] = root;
      }
    }
    cout << ans - 1 << endl;
  } else {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (father[i] != i) {
        continue;
      }
      ans++;
      if (!root) {
        root = i;
      }
      a[i] = root;
    }
    cout << ans << endl;
  }
  while ((clock() - Begin) / CLOCKS_PER_SEC <= 0.6);
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}

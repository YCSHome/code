#include <iostream>
#include <vector>
#include <bitset>
#include <set>

using namespace std;

const int kMaxN = 1e6;

int map[20][20] = {
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0}, // only 1
  {0,0,0,1,1,1,0}, // 3 with 4
  {0,0,1,0,1,0,1}, // only 2
  {0,0,1,1,0,1,1}, // only 4
  {0,1,0,0,1,0,0}, // 1 with 4
  {0,1,0,1,0,1,0}, // only 3
  {0,1,1,0,0,0,1}, // 2 with 4
  {0,1,1,1,1,1,1}, // none
};

int x;
int n, c;
bitset<100> s;
bool mustOn[kMaxN];
bool mustOff[kMaxN];
bool flag = false;

bool check(int x) {
  for (int i = 1; i <= 6; i++) {
    if (mustOff[i] && map[x][i]) {
      return false;
    }
    if (mustOn[i] && map[x][i] == false) {
      return false;
    }
  }
  return true;
}

void print(int x) {
  if (check(x)) {
    flag = true;
    for (int i = 1; i <= n; i++) {
      cout << map[x][(i - 1) % 6 + 1];
    }
    cout << endl;
  }
}

int main() {
  cin >> n >> c;
  int x;
  while (1) {
    cin >> x;
    if (x == -1) break;
    mustOn[(x - 1) % 6 + 1] = true;
  }
  while (1) {
    cin >> x;
    if (x == -1) break;
    mustOff[(x - 1) % 6 + 1] = true;
  }
  if (c == 0) {
    print(8);
  }
  if (c == 1) {
    print(1);
    print(3);
    print(4);
    print(6);
  }
  if (c == 2) {
    for (int i = 1; i <= 8; i++) {
      if (i != 4) print(i);
    }
  }
  if (c >= 3) {
    for (int i = 1; i <= 8; i++) {
      print(i);
    }
  }
  if (!flag) {
    cout << "IMPOSSIBLE";
  }
  return 0;
}

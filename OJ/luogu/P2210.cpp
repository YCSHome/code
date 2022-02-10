#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
const double END = 1e-3;
const double res = 0.99;
const int baoli = 1e4;
const double ENDTIME = 0.96;

int n;
int p[MAXN];
int ans = INT_MAX;
vector<int> Friend[MAXN];

bool Continue() {
  return (clock() / (double)CLOCKS_PER_SEC) <= ENDTIME;
}

double RAND() {
  return (double)rand() / RAND_MAX;
}

int get_ans() {
  int temp = 0;
  for (int i = 1; i <= n; i++) {
    for (int j : Friend[i]) {
      temp += abs(p[i] - p[j]);
    }
  }
  return temp;
}

void work() {
  double T = 1e6;
  while (T > END) {
    int x, y;
    do {
      x = rand() % n + 1;
      y = rand() % n + 1;
    } while (x == y);
    swap(p[x], p[y]);
    int t = get_ans();
    if (t <= ans) {
      ans = t;
    } else if (exp((ans - t) / T) > RAND()) {
      swap(p[x], p[y]);
    }
    T *= res;
  }
} 
 
int main() {
  srand(time(nullptr));
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 3; j++) {
      int t;
      cin >> t;
      Friend[i].push_back(t);
    }
    p[i] = i;
  }
  while (Continue()) {
    work();
  }
  cout << ans / 2 << endl;
  return 0;
}

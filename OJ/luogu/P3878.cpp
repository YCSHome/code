#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3;
const double END = 1e-8;
const double res = 0.94;

double RAND() {
  return (double)rand() / RAND_MAX;
}

int v[MAXN];
long long ans = 0;
int n;
int a, b;
int A[MAXN], B[MAXN];

long long get_ans() {
  long long tempa = 0, tempb = 0;
  for (int i= 1; i <= a; i++) {
    tempa += A[i];
  }
  for (int i= 1; i <= b; i++) {
    tempb += B[i];
  }
  return abs(tempa - tempb);
}

void SA() {
  double T = 1e6;
  while (T > END) {
    int x = rand() % a + 1;
    int y = rand() % b + 1;
    swap(A[x], B[y]);
    long long t = get_ans();
    if (t < ans) {
      ans = t;
    } else if ((double)exp((ans - t) / T) < RAND()) {
      swap(A[x], B[y]);
    }
    T *= res;
  }
}

void solve() {
  ans = LLONG_MAX;
  cin >> n;
  if (n == 0) {
    cout << 0 << endl;
    return;
  }
  a = n / 2;
  b = n - a;
  for (int i = 1; i <= a; i++) {
    cin >> A[i];
  }
  for (int i = 1; i <= b; i++) {
    cin >> B[i];
  }
  for (int i = 1; i <= 500; i++) SA();
  cout << ans << endl;
}

int main() {
  srand(time(NULL));
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

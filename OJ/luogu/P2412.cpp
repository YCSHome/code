#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
const int MAXLOG = 30;

class ST {
private:
  int LOG[MAXN];
  int (*a)[MAXN];

public:
  void build(int a[][MAXN], int n) {
    this->a = a;
    LOG[1] = 0;
    LOG[2] = 1;
    for (int i = 3; i < MAXN; i++) {
      LOG[i] = LOG[i / 2] + 1;
    }
    for (int j = 1; j < MAXLOG - 1; j++) {
      for (int i = 1; i <= n; i++) {
        if (i + (1 << j) - 1 <= n) {
          a[j][i] = max(a[j - 1][i], a[j - 1][i + (1 << (j - 1))]);
        }
      }
    }
  }

  int get(int l, int r) {
    int k = LOG[(r - l + 1)];
    return max(a[k][l], a[k][r - (1 << k) + 1]);
  }

  ST() {}
  ST(int a[][MAXN], int n) { build(a, n); }
};

struct word {
  string a;
  string b;
  int id;
  bool operator<(const word& cmp) const { return b < cmp.b; };
} words[MAXN];

int n, m;
int a[MAXLOG][MAXN];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> words[i].a;
    for (int j = 0; j < words[i].a.size(); j++) {
      if (words[i].a[j] <= 'Z')
        words[i].b += words[i].a[j] + 32;
      else
        words[i].b += words[i].a[j];
    }
    words[i].id = i;
  }
  sort(words + 1, words + 1 + n);
  for (int i = 1; i <= n; i++) {
    a[0][words[i].id] = i;
  }
  ST st(a, n);
  for (int i = 1; i <= m; i++) {
    int l, r;
    cin >> l >> r;
    cout << words[st.get(l, r)].a << endl;
    // cout << st.get(l, r) << " " << words[st.get(l, r)].str << endl;
  }
  return 0;
}

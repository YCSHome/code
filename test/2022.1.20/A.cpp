#include <bits/stdc++.h>

using namespace std;

string s[10] = {"?", "Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

int n;
bool must[10][10];
vector<int> v;

int get(const string& str) {
  for (int i = 1; i <= 8; i++) {
    if (str == s[i]) {
      return i;
    }
  }
  return 0;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string A, B;
    cin >> A >> B >> B >> B >> B >> B;
    int a = get(A), b = get(B);
    must[a][b] = must[b][a] = true;
  }
  for (int i = 1; i <= 8; i++) v.push_back(i);
  do {
    int cnt = 0;
    for (int i = 0; i < v.size() - 1; i++) {
      cnt += must[v[i]][v[i + 1]];
    }
    if (cnt == n) {
      for (int i : v) {
        cout << s[i] << endl;
      }
      return 0;
    }
  } while (next_permutation(v.begin(), v.end()));
  cout << "fuck";
  return 0;
}

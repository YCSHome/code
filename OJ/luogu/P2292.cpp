#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int n, m;
int trie[kMaxN + 1000][26];
int tot = 0;
bool End[kMaxN];
string str[kMaxN];

void insert(const string& str) {
  int p = 0;
  for (int i = 0; i < str.size(); i++) {
    int ch = str[i] - 'a';
    if (trie[p][ch] == 0) {
      trie[p][ch] = ++tot;
    }
    p = trie[p][ch];
  }
  End[p] = true;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> str[i];
    insert(str[i]);
  }
  string temp;
  for (int i = 1; i <= m; i++) {
    cin >> temp;
    for (int i = 0; i < temp.size(); i++) {
      int p = 0;
      int j = i;
      for (; j < temp.size(); j++) {
        p = trie[p][temp[j] - 'a'];
        if (p == 0) {
          cout << i << endl;
          goto End;
        }
        if (End[p]) {
          i = j;
        }
      }
    }
    cout << temp.size() << endl;
End:;
  }
  return 0;
}

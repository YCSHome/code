#include <iostream>
#include <vector>

using namespace std;

const int S = 1145;
const int MOD = 1e5;
const int kMaxN = 1e6;

int n;
vector<string> Hash[kMaxN];

int getHash(const string &str) {
  long long ans = 0;
  for (int i = 1; i < str.size(); i++) {
    ans = (ans * S + str[i]) % MOD;
  }
  return ans;
}

int main() {
  cin >> n;
  int ans = 0;
  string str;
  while (n--) {
    cin >> str;
    str = '#' + str;
    int a = getHash(str);
    bool flag = true;
    for (const auto& i : Hash[a]) {
      if (i == str) {
        flag = false;
      }
    }
    if (flag) {
      Hash[a].push_back(str);
      ans++;
    }
  }
  cout << ans;
  return 0;
}

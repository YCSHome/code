#include <iostream>
#include <vector>

using namespace std;

const int kMaxN = 5e5 + 10;

vector<int> go[kMaxN];

int Max[kMaxN][3];
int Min[kMaxN][3];
string str;
int tot = 0;

void build(int x) {
  tot++;
  if (str[x] >= '1') { go[x].push_back(tot + 1), build(tot + 1); }
  if (str[x] >= '2') { go[x].push_back(tot + 1), build(tot + 1); }
}

void dfs(int x) {
  if (go[x].size() == 0) {
    Max[x][0] = Min[x][0] = 1;
  } else if (go[x].size() == 1) {
    int v = go[x].front();
    dfs(v);
    Max[x][0] = max(Max[v][1], Max[v][2]) + 1;
    Max[x][1] = max(Max[v][0], Max[v][2]);
    Max[x][2] = max(Max[v][0], Max[v][1]);
    Min[x][0] = min(Min[v][1], Min[v][2]) + 1;
    Min[x][1] = min(Min[v][0], Min[v][2]);
    Min[x][2] = min(Min[v][0], Min[v][1]);
  } else {
    int l = go[x][0], r = go[x][1];
    dfs(l), dfs(r);
    Max[x][0] = max(Max[l][1] + Max[r][2], Max[l][2] + Max[r][1]) + 1;
    Max[x][1] = max(Max[l][0] + Max[r][2], Max[l][2] + Max[r][0]);
    Max[x][2] = max(Max[l][0] + Max[r][1], Max[l][1] + Max[r][0]);
    Min[x][0] = min(Min[l][1] + Min[r][2], Min[l][2] + Min[r][1]) + 1;
    Min[x][1] = min(Min[l][0] + Min[r][2], Min[l][2] + Min[r][0]);
    Min[x][2] = min(Min[l][0] + Min[r][1], Min[l][1] + Min[r][0]);
  }
}

int main() {
  cin >> str;
  str = '#' + str;
  build(1);
  dfs(1);
  int M = 0, m = 0x3f3f3f3f;
  for (int i = 0; i < 3; i++) m = min(m, Min[1][i]);
  cout << Max[1][0] << " " << m << endl;
  return 0;
}

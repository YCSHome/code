#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

const int kMaxN = 50;

int L, R, C;
int sl, sr, sc;
int el, er, ec;
int dis[kMaxN][kMaxN][kMaxN];
bool unable[kMaxN][kMaxN][kMaxN];
const int dl[6] = {0, 0, 1, -1, 0, 0};
const int dr[6] = {1, -1, 0, 0, 0, 0};
const int dc[6] = {0, 0, 0, 0, 1, -1};

queue<tuple<int, int, int>> q;

void record(int l, int r, int c, int d) {
  if (l < 1 || l > L || r < 1 || r > R || c < 1 || c > C || ~dis[l][r][c] || unable[l][r][c]) {
    return;
  }
  dis[l][r][c] = d;
  q.push(make_tuple(l, r, c));
}

int bfs() {
  record(sl, sr, sc, 0);
  while (!q.empty()) {
    int l = get<0>(q.front());
    int r = get<1>(q.front());
    int c = get<2>(q.front());
    q.pop();
    for (int i = 0; i < 6; i++) {
      int nl = l + dl[i], nr = r + dr[i], nc = c + dc[i];
      record(nl, nr, nc, dis[l][r][c] + 1);
    }
  }
  return dis[el][er][ec];
}

int main() {
  memset(dis, -1, sizeof(dis));
  cin >> L >> R >> C;
  for (int l = 1; l <= L; l++) {
    for (int r = 1; r <= R; r++) {
      for (int c = 1; c <= C; c++) {
        char ch;
        cin >> ch;
        if (ch == '#') { unable[l][r][c] = true; }
        if (ch == 'S') { sl = l, sr = r, sc = c; }
        if (ch == 'E') { el = l, er = r, ec = c; }
      }
    }
  }
  int ans = bfs();
  if (ans == -1) {
    cout << "Trapped!" << endl;
  } else {
    cout << "Escaped in " << ans << " minute(s)." << endl;
  }
  return 0;
}

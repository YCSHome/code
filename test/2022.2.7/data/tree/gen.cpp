#include <bits/stdc++.h>

#define For(i, j, k) for (int i = j; i <= k; i++)

using namespace std;

const int TASK = 5;
const int CASE = 5;
const int limN[TASK] = {1000, 100000, 100000, 100000, 300000};
const int mx = 1e7;

// subtask2 : no op 1
// subtask3 : no op 2
// subtask4 : u = v for op 2

int randint(int l, int r) { return rand() % (r - l + 1) + l; }

int main() {
  srand(time(0));

  For(t, 1, TASK) {
    char cmd[100];
    sprintf(cmd, "mkdir subtask%d", t);
    system(cmd);

    For(c, 1, CASE) {
      if (c == 5 && (t == 1 || t == 3)) continue;

      sprintf(cmd, "subtask%d/%d.in", t, c);
      freopen(cmd, "w", stdout);

      int n = limN[t - 1] - rand() % 10, q = limN[t - 1] - rand() % 10;
      printf("%d %d\n", n, q);
      For(i, 1, n) printf("%d%c", randint(-mx, mx), i == n ? '\n' : ' ');

      int _u = 1, _v = 1;
      switch (c) {
        case 1:
          For(i, 2, n) printf("%d %d\n", i, randint(1, i - 1));
          break;
        case 2:
        case 5:
          For(i, 2, n) printf("%d %d\n", i, max(1, randint(i - 4, i - 1)));
          break;
        case 3:
          For(i, 2, n) {
            if (rand() % 2)
              printf("%d %d\n", i, _u), _u = i;
            else
              printf("%d %d\n", i, _v), _v = i;
          }
          break;
        case 4:
          For(i, 2, n) printf("%d %d\n", i, rand() % 2 ? 1 : randint(1, i - 1));
          break;
      }

      while (q) {
        int x = rand() % 10, op = x < 2 ? 1 : (x < 6 ? 2 : 3);

        if (t == 2 && op == 1) continue;
        if (t == 3 && op == 2) continue;
        if (c == 5 && op != 2) continue;

        if (op == 1) {
          printf("1 %d\n", randint(1, n));
        } else if (op == 2) {
          int u = randint(1, n), v = randint(1, n);
          if (t == 4) {
            v = u;
            if (c == 4 && rand() % 2) u = v = 1;
          }
          printf("2 %d %d %d\n", u, v, randint(-mx, mx));
        } else if (op == 3) {
          int u = randint(1, n);
          if (c == 4 && rand() % 2) u = 1;
          printf("3 %d\n", u);
        }

        --q;
      }

      sprintf(cmd, "time ./tree < subtask%d/%d.in > subtask%d/%d.out", t, c, t,
              c);
      freopen("tmp", "w", stdout);
      system(cmd);
    }
  }

  return 0;
}

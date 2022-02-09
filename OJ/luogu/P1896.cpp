#include <cstring>
#include <iostream>

using namespace std;

// int n, k;

// long long stand[2005];
// long long sit[2005];
// long long f[15][2005][200];
// int       cnt = 0;

// void dfs(int x, int num, int now) {
//   if (now >= n) {
//     sit[++cnt] = x;
//     stand[cnt] = num;
//     return;
//   }
//   dfs(x, num, now + 1);
//   dfs(x + (1 << now), num + 1, now + 2);
// }

// bool check(int j, int x) {
//   if (sit[j] & sit[x])
//     return false;
//   if ((sit[j] << 1) & sit[x])
//     return false;
//   if (sit[j] & (sit[x] << 1))
//     return false;
//   return true;
// }

// long long solve(int n_, int k_) {
//   n = n_, k = k_;
//   memset(stand, 0, sizeof(stand));
//   memset(sit, 0, sizeof(sit));
//   memset(f, 0, sizeof(f));
//   cnt = 0;
//   dfs(0, 0, 0);
//   for(int j = 1; j <= cnt; j++) {
//     f[1][j][stand[j]] = 1;
//   }
//   for (int i = 2; i <= n; i++) {
//     for (int j = 1; j <= cnt; j++) {
//       for (int x = 1; x <= cnt; x++) {
//         if (!check(j, x)) continue;
//         for (int l = stand[j]; l <= k; l++) {
//           f[i][j][l] += f[i - 1][x][l - stand[j]];
//         }
//       }
//     }
//   }
//   long long ans = 0;
//   for (int i = 1; i <= cnt; i++) {
//     ans += f[n][i][k];
//   }
//   return ans;
// }

// int main() {
//   freopen("test", "w", stdout);
//   for (int i = 1; i <= 9; i++) {
//     cout << "{";
//     for (int k = 0; k <= i * i; k++) {
//       if (k != 0) cout << ", ";
//       cout << solve(i, k);
//     }
//     cout << "},";
//     cout <<endl;
//   }
//   return 0;
// }

long long ans[10][100] = {
    {},
    {1, 1},
    {1, 4, 0, 0, 0},
    {1, 9, 16, 8, 1, 0, 0, 0, 0, 0},
    {1, 16, 78, 140, 79, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 25, 228, 964, 1987, 1974, 978, 242, 27, 1, 0, 0, 0,
     0, 0,  0,   0,   0,    0,    0,   0,   0,  0, 0, 0, 0},
    {1, 36, 520, 3920, 16834, 42368, 62266, 51504, 21792, 3600, 0, 0, 0,
     0, 0,  0,   0,    0,     0,     0,     0,     0,     0,    0, 0, 0,
     0, 0,  0,   0,    0,     0,     0,     0,     0,     0,    0},
    {1,       49,      1020,   11860,  85275, 397014, 1220298, 2484382, 3324193,
     2882737, 1601292, 569818, 129657, 18389, 1520,   64,      1,       0,
     0,       0,       0,      0,      0,     0,      0,       0,       0,
     0,       0,       0,      0,      0,     0,      0,       0,       0,
     0,       0,       0,      0,      0,     0,      0,       0,       0,
     0,       0,       0,      0,      0},
    {1,        64,        1806,      29708,     317471,    2326320,   12033330,
     44601420, 119138166, 229095676, 314949564, 305560392, 204883338, 91802548,
     25952226, 4142000,   281571,    0,         0,         0,         0,
     0,        0,         0,         0,         0,         0,         0,
     0,        0,         0,         0,         0,         0,         0,
     0,        0,         0,         0,         0,         0,         0,
     0,        0,         0,         0,         0,         0,         0,
     0,        0,         0,         0,         0,         0,         0,
     0,        0,         0,         0,         0,         0,         0,
     0,        0},
    {1,           81,
     2968,        65240,
     962089,      10087628,
     77784658,    450193818,
     1979541332,  6655170642,
     17143061738, 33787564116,
     50734210126, 57647295377,
     49138545860, 31122500764,
     14518795348, 4959383037,
     1237072414,  224463798,
     29275410,    2673322,
     163088,      6150,
     125,         1,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0,
     0,           0}};

int read() {
  int num = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') num = num * 10 + ch - '0', ch = getchar();
  return num;
}

void write(long long num) {
  if (num >= 10) {
    write(num / 10);
  }
  putchar(num % 10 + '0');
}

int main() {
  write(ans[read()][read()]);
  return 0;
}

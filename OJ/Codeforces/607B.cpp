#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1e3;

int n;
int a[MAXN];
int dp[MAXN][MAXN];

int main() {
    memset(dp, 0x3f, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][i] = dp[i][i - 1] = 1;
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (a[l] == a[r]) {
                dp[l][r] = min(dp[l][r], dp[l + 1][r - 1]);
            }
            for (int k = l; k < r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}


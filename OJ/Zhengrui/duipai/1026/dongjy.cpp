#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
long long a[1000][1000];

signed main() {
	cin >> n >> m;
	for (int i = 1; i < n; ++i) {
		for (int j = 1, x; j <= m; ++j) {
			cin >> x;
			a[i + 1][j] -= x + a[i][j];
		}
	}
	for (int j = 1, x; j < m; ++j) {
		cin >> x;
		a[n][j + 1] -= x + a[n][j];
	}
	int x;
	cin >> x;
	if (x + a[n][m] == 0) {
		puts("Yes");
	} else {
		puts("No");
	}
	return 0;
}

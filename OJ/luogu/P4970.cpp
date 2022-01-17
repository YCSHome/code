#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int n, m, temp = 0;
int a[MAXN], ans = 0;
bool b[MAXN];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	while (m--) {
		int opt, x, value, l, r;
		cin >> opt;
		if (opt == 1) {
			cin >> x >> value;
			a[x] = value - a[x];
			b[x] = true;
		} else if (opt == 2) {
			cin >> l >> r;
			value = 0;
			for (int i = r; i >= l; i--) {
				if (b[i]) {
					temp = i;
					b[i] = false;
					value = a[i];
					break;
				}
				if (value < a[i]) temp = i, value = a[i];
			}
			a[temp] = 0;
			ans += value;
			cout << value << endl;
		} else {
			cin >> l >> r >> value;
			for (int i = l; i <= r; i++) a[i] += value;
		}
	}
	if (ans < 1000) {
		cout << "QAQ";
	} else if (ans >= 10000 && ans < 10000000) {
		cout << "Sakura";
	} else {
		cout << "ice";
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n, ans;
int a[1000010];
int minn[1000010], minn2[1000010];
int b[1000010];

inline int read() {
	int s(0), f(1);
	char ch(getchar());
	while (ch < '0' || ch > '9') {
		if (ch == '-') {
			f = -1;
		}
		ch = getchar();
	}
	while (ch > '/' && ch < ':') {
		s = (s << 3) + (s << 1) + ch - '0';
		ch = getchar();
	}
	return s * f;
}

int main() {
	n = read();
	minn[0] = 1e9 + 1;
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		b[i] = b[i - 1] + a[i];
		minn[i] = min(minn[i - 1], b[i]);
	}
	minn[0] = 0, b[n + 1] = 0;
	for (int i = n; i > 0; --i) {
		b[i] = b[i + 1] + a[i];
		minn2[i] = min(minn2[i + 1] + a[i], a[i]);
		if (minn2[i] > -1 && minn[i - 1] + b[i] >= 0) {
			++ans;
		}
	}
	cout << ans;
	return 0;
}

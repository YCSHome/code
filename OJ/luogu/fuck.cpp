#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[100010], b[100010];

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

inline void write(int x) {
	if (x > 9) {
		write(x / 10);
	}
	putchar(x % 10 + '0');
}

int main() {
	t = read();
	while (t--) {
		n = read();
		for (int i = 1; i <= n; ++i) {
			a[i] = read();
		}
		sort(a + 1, a + 1 + n);
		int l(1), r(1);
		bool flag(true);
		for (int i = 2; i <= n; ++i) {
			if (a[i] == a[i - 1]) {
				++r;
			} else {
				if (l == r) {
					flag = false;
					break;
				}
				for (int j = l; j < r; ++j) {
					b[j] = j + 1;
				}
				b[r] = l;
				l = r = i;
			}
		}
		if (l == r) {
			puts("-1");
			continue;
		}
		for (int j = l; j < r; ++j) {
			b[j] = j + 1;
		}
		b[r] = l;
		if (flag) {
			for (int i = 1; i <= n; ++i) {
				write(b[i]);
				putchar(' ');
			}
			puts("");
		} else {
		}
	}
	return 0;
}

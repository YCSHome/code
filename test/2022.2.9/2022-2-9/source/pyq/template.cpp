#include<bits/stdc++.h>
using namespace std;
#define rep(i, d, u) for(int i = d; i <= u; ++i)
#define dep(i, u, d) for(int i = u; i >= d; --i)
#define cep(n) while(n--)
#define gep(i, a) for(int i = firs[a]; i; i = neig[i])
int ured() {
	int ch, re = 0;
	do {
		ch = getchar();
	} while('9' < ch || ch < '0');
	do {
		re = re * 10 + (ch ^ '0');
	} while('0' <= (ch = getchar()) && ch <= '9');
	return re;
}
void uwit(int da) {
	int ch[21], cn = 0;
	do {
		ch[++cn] = da - da / 10 * 10;
	} while(da /= 10);
	do {
		putchar('0' ^ ch[cn]);
	} while(--cn);
}
int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
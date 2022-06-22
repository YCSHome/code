#include <bits/stdc++.h>
using namespace std;
char c;
int cnt[30], ans;
int main() {
	freopen("herd.in", "r", stdin);
	freopen("herd.out", "w", stdout);
	while(cin >> c)
		cnt[c - 'a']++, ans = max(ans, cnt[c - 'a']);
	cout << ans;
    return 0;
}

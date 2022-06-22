#include <bits/stdc++.h>
using namespace std;
map<int, bool> vis[100005];
int n, k, m, a[100005], ans[100005], x[100005], y[100005];
int main() {
	freopen("dance.in", "r", stdin);
	freopen("dance.out", "w", stdout);
	cin >> n >> k >> m;
	for(int i = 1; i <= n; i++)
		a[i] = i, ans[i] = 1, vis[i][i] = 1;
	for(int i = 1; i <= k; i++)
		cin >> x[i] >> y[i];
	for(int cur = 1; cur <= m; )
		for(int i = 1; i <= k && cur <= m; i++, cur++) {
			swap(a[x[i]], a[y[i]]);
			if(!vis[y[i]][a[y[i]]])
				ans[a[y[i]]]++, vis[y[i]][a[y[i]]] = 1;
			if(!vis[x[i]][a[x[i]]])
				ans[a[x[i]]]++, vis[x[i]][a[x[i]]] = 1;
		}
	for(int i = 1; i <= n; i++)
		cout << ans[i] << '\n';
	return 0;
}

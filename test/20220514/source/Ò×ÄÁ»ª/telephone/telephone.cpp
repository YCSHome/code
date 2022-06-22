#include <bits/stdc++.h>
using namespace std;
char c[55][55];
bool vis[50005];
int n, k, cnt, a[50005], head[50005], dis[50005], pre[50005][55], nxt[50005][55];
struct node {
	int to, w, nxt;
}e[500005];
struct Node {
	int id, dist;
	bool operator < (const Node &b) const {
		return dist > b.dist;
	}
};
void add(int x, int y, int w) {
	e[++cnt].to = y, e[cnt].w = w, e[cnt].nxt = head[x], head[x] = cnt;
	return;
}
void dij() {
	priority_queue<Node> pq;
	for(int i = 1; i <= n; i++)
		dis[i] = 1e9;
	dis[1] = 0, pq.push((Node){1, 0});
	while(!pq.empty()) {
		int x = pq.top().id;
		pq.pop();
		if(vis[x])
			continue;
		vis[x] = 1;
		for(int i = head[x]; i; i = e[i].nxt)
			if(dis[e[i].to] > dis[x] + e[i].w)
				dis[e[i].to] = dis[x] + e[i].w, pq.push((Node){e[i].to, dis[e[i].to]});
	}
	return;
}
int main() {
	freopen("telephone.in", "r", stdin);
	freopen("telephone.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= k; i++)
		for(int j = 1; j <= k; j++)
			cin >> c[i][j];
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++)
			pre[i][j] = pre[i - 1][j];
		pre[i][a[i - 1]] = i - 1;
	}
	for(int i = n; i; i--) {
		for(int j = 1; j <= k; j++)
			nxt[i][j] = nxt[i + 1][j];
		nxt[i][a[i + 1]] = i + 1;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= k; j++) {
			if(c[a[i]][j] - '0' && pre[i][j])
				add(i, pre[i][j], abs(pre[i][j] - i));
			if(c[a[i]][j] - '0' && nxt[i][j])
				add(i, nxt[i][j], abs(nxt[i][j] - i));
			if(c[a[i]][a[n]] - '0')
				add(i, n, abs(n - i));
		}
	dij();
	if(dis[n] < 1e9)
		cout << dis[n];
	else
		cout << -1;
	return 0;
}

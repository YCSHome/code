#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e7;

struct edge {
  int v;
  int next;
}e[MAXN];

int head[MAXN];
int tot = 0;

void add(int u, int v) {
  e[++tot] = {v, head[u]};
  head[u] = tot;
}

long long n;
long long w[MAXN];
long long f1[MAXN], f2[MAXN];
long long cnt[MAXN], pos[MAXN], size[MAXN], t[MAXN];
long long pos2[MAXN];
bool vis[MAXN];

void dfs(int x, int fa) {
	int c = w[x], k = t[c];
	int flag = 0, p = 0;
	size[x] = 1;
	
  for (int i = head[x]; i; i = e[i].next) {
    int y = e[i].v;
		if(y == fa) continue;
		int lastans = t[c];
		dfs(y, x);
		f1[x] += 1LL * size[x] * size[y];
		size[x] += size[y];
		if(lastans != t[c]) flag++, p = y;
	}
	f1[x] += 1LL * size[x] * (n - size[x]);
	if(k || t[c] != cnt[c] - 1) flag++;
	t[c]++; // 当前节点颜色是 c
	
	if(flag == 1) { // 端点 
		if(!pos2[c]) pos[c] = x;
		else {
			int p2 = p ? n - size[p] : size[x];
			f2[c] = 1LL * size[pos[c]] * p2;
		} pos2[c]++;	
	}
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
    cnt[w[i]]++;
    pos[w[i]] = i;
  }
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    add(u, v);
    add(v, u);
  }
  dfs(1, 0);
  
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 0) {
      cout << n * (n - 1) / 2 << endl;
    } else if (cnt[i] == 1) {
      cout << f1[pos[i]] << endl;
    } else if (pos2[i] == 2) {
      cout << f2[i] << endl;
    } else {
      cout << 0 << endl;
    }
  }
  return 0;
}

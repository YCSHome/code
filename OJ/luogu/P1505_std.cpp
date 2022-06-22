#include <bits/stdc++.h>
#define ll long long
#define ri register int
#define IO ios::sync_with_stdio(false)
#define mid ((a[x].l+a[x].r)>>1)
using namespace std;
template < typename T >
inline void read(T &x){
	x = 0;bool flag = 1;char c = getchar();
	while(c < '0' or c > '9'){
		if(c == '-') flag = 0;
		c = getchar();
	}
	while(c >= '0' and c <= '9'){
		x = (x << 1) + (x << 3) + (c^48);	c = getchar();
	}
	x = (flag) ? x : -x ;
}
template < typename T >
void print(T x)
{
	if(x < 0){putchar('-'),x=-x;}
	if(x>9)print(x/10);
	putchar(int (x%10) + '0');
}

const int N = 2e5 + 10;
int head[N],dfn[N],top[N],siz[N],fa[N],son[N],va[N],val[N],dep[N],x[N],y[N];
int to[N<<1],nxt[N<<1],w[N<<1];
int n,m,cnt,tim;
struct node{
	int l,r,mins,sum,maxs,laz;
}a[N<<2];

inline void add(int u,int v,int val){to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt,w[cnt]=val;}

void dfs1(int x,int f){
	fa[x]=f,siz[x]=1,dep[x]=dep[f]+1;
	int ms=-1;
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		va[v]=w[i];
		dfs1(v,x);
		siz[x]+=siz[v];
		if(ms<siz[v]) ms=siz[v],son[x]=v;
	}
}

void dfs2(int x,int t){
	top[x]=t,dfn[x]=++tim,val[tim]=va[x];
	if(!son[x]) return;
	dfs2(son[x],t);
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(v==fa[x]||v==son[x])continue;
		dfs2(v,v);
	}
}

//seg
inline void pushup(int x){
	a[x].sum=a[x<<1].sum+a[x<<1|1].sum;
	a[x].maxs=max(a[x<<1].maxs,a[x<<1|1].maxs);
	a[x].mins=min(a[x<<1].mins,a[x<<1|1].mins);
}
inline void ch(int x){
	int tmp=a[x].maxs;
	a[x].laz^=1;
	a[x].maxs=-a[x].mins,a[x].mins=-tmp,a[x].sum=-a[x].sum;
}
inline void pushdown(int x){
	if(!a[x].laz) return;
	ch(x<<1),ch(x<<1|1);
	a[x].laz^=1;
}

void build(int x,int l,int r){
	a[x].l=l,a[x].r=r;
	if(l==r) return a[x].mins=a[x].maxs=a[x].sum=val[l],void();
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	pushup(x);
}

void mpoint(int x,int p,int k){
	if(a[x].l==a[x].r) return a[x].sum=a[x].mins=a[x].maxs=k,void();
	pushdown(x);
	if(p<=mid)mpoint(x<<1,p,k);
	else mpoint(x<<1|1,p,k);
	pushup(x);
}

void modify(int x,int l,int r){
	if(a[x].l>=l&&a[x].r<=r) return ch(x),void();
	pushdown(x);
	if(l <= mid) modify(x<<1,l,r);
	if(mid < r ) modify(x<<1|1,l,r);
	pushup(x);
}

int qsum(int x,int l,int r){
	if(a[x].l>=l&&a[x].r<=r) return a[x].sum;
	pushdown(x);
	int res=0;
	if(l<=mid) res+=qsum(x<<1,l,r);
	if(mid <r) res+=qsum(x<<1|1,l,r);
	return res;
}

int qmin(int x,int l,int r){
	if(a[x].l>=l&&a[x].r<=r) return a[x].mins;
	pushdown(x);
	int res=0x7fffffff;
	if(l<=mid) res=min(res,qmin(x<<1,l,r));
	if(mid <r) res=min(res,qmin(x<<1|1,l,r));
	return res;
}

int qmax(int x,int l,int r){
	if(a[x].l>=l&&a[x].r<=r) return a[x].maxs;
	pushdown(x);
	int res=-0x7fffffff;
	if(l<=mid) res=max(res,qmax(x<<1,l,r));
	if(mid <r) res=max(res,qmax(x<<1|1,l,r));
	return res;
}

void mchain(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		modify(1,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x,y);
	modify(1,dfn[x]+1,dfn[y]);
}

int qcsum(int x,int y){
	int res=0;
	while(top[x]!=top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		res+=qsum(1,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	res+=qsum(1,dfn[x]+1,dfn[y]);
	return res;
}

int qcmin(int x,int y){
	int res=0x7fffffff;
	while(top[x]!=top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		res=min(res,qmin(1,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	res=min(res,qmin(1,dfn[x]+1,dfn[y]));
	return res;
}

int qcmax(int x,int y){
	int res=-0x7fffffff;
	while(top[x]!=top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		res=max(res,qmax(1,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	res=max(res,qmax(1,dfn[x]+1,dfn[y]));//记得要+1
	return res;
}

void medge(int u,int v,int w){
	if(fa[u]==v) mpoint(1,dfn[u],w);
	else mpoint(1,dfn[v],w);
}

int main(int argc,const char *argv[]){
	freopen("t.out", "w", stdout);
	string tmp;
	int u,v,w;
	read(n);
	for(int i = 1; i < n ; i++){
		read(u),read(v),read(w);
		x[i]=u+1,y[i]=v+1;
		add(u+1,v+1,w),add(v+1,u+1,w);
	}
	dfs1(1,1),dfs2(1,1),build(1,1,n);
	read(m);
	while(m--){
		cin >> tmp;
		cout << tmp << endl;
		read(u),read(v);
		if(tmp=="C") medge(x[u],y[u],v);
		else if(tmp=="N") mchain(u+1,v+1);
		else if(tmp=="SUM") print(qcsum(u+1,v+1)),putchar('\n');
		else if(tmp=="MIN") print(qcmin(u+1,v+1)),putchar('\n');
		else if(tmp=="MAX") print(qcmax(u+1,v+1)),putchar('\n');
		for (int i = 1; i <= n; i++) {
			cout << qsum(1, i, i) << " ";
		}
		cout << endl;
	}
	return 0;
}

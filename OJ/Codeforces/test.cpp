#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

const int N=2e5+10;

int n,fir[N],tot,col[N],fa[N];
struct node {int to,nex;} e[N << 1];

void add(int u,int v)
{
	e[++tot].to=v;
	e[tot].nex=fir[u];
	fir[u]=tot;
	return ;
}

void init(int x,int dad)
{
	fa[x]=dad;
	for(int i=fir[x];i;i=e[i].nex)
		if(e[i].to^dad) init(e[i].to,x);
	return ; 
}

void dfs(int x)
{
	printf("%d ",x);
	for(int i=fir[x];i;i=e[i].nex)
		if(e[i].to^fa[x])
		{
			col[e[i].to]^=1;//往子树走
			dfs(e[i].to);
			printf("%d ",x);
			col[x]^=1;//回来
			if(!col[e[i].to])//处理儿子颜色
			{
				printf("%d %d ",e[i].to,x);
				col[e[i].to]=1;
				col[x]^=1;
			}
		}
	return ;
}

int main()
{
//	freopen("work.in","r",stdin); freopen("work.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {scanf("%d",&col[i]); if(col[i] < 0) col[i]=0;}
	for(int i=1,u,v;i<n;i++) {scanf("%d%d",&u,&v); add(u,v); add(v,u);}
	init(1,0); dfs(1);
  cout << endl;
  for (int i = 1; i <= n; i++) {
    cout << col[i] << " ";
  }
  cout << endl;
	if(!col[1]) printf("%d 1 %d ",e[fir[1]].to,e[fir[1]].to);//最后的白点
//	fclose(stdin); fclose(stdout);
	return 0;
}

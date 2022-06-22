#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
int head[505],dfn[505],low[505],vis[505],stack[505];
bool cut[505],in_stack[505];
int n,m,cnt,num,tot,deg,ans1,T,cases,root,top;
ll ans2;
struct node
{
  int from;
  int to;
  int next;
}e[1010];
inline void first()
{
  memset(head,0,sizeof(head));
  memset(dfn,0,sizeof(dfn));
  memset(low,0,sizeof(low));
  memset(cut,0,sizeof(cut));
  memset(vis,0,sizeof(vis));
  top=cnt=tot=n=ans1=T=0; ans2=1;
}
inline void insert(int from,int to)
{
  e[++num].from=from;
  e[num].to=to;
  e[num].next=head[from];
  head[from]=num;
}
inline int read()
{
  int x=0,f=1; char c=getchar();
  while (c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while (c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
  return x*f;
}
void Tarjan(int now,int father)//求割点 
{
  dfn[now]=low[now]=++tot;
  for(int i=head[now];i;i=e[i].next)
  {
    int v=e[i].to;
    if(!dfn[v])
    {
      Tarjan(v,now);
      low[now]=min(low[now],low[v]);
      if(low[v]>=dfn[now])
      {
        if(now==root) deg++;
        else cut[now]=true;
      }
    }
    else if(v!=father) low[now]=min(low[now],dfn[v]);//不要跟求环混了 具体原理去网上找 
  }
}
void dfs(int x)//遍历每个连通块 
{
  vis[x]=T;//标记 
  if(cut[x]) return;
  cnt++;//数量 
  for(int i=head[x];i;i=e[i].next)
  {
    int v=e[i].to;
    if(cut[v]&&vis[v]!=T) num++,vis[v]=T;//统计割点数目。 
                                         //如果是割点且标记不与遍历的的连通块相同就修改标记。 
    if(!vis[v])dfs(v);
  }
}
int main()
{
  m=read();
  while (m)
  {
    first();
    for (int i=1;i<=m;i++)
    {
      int u=read(),v=read();
      n=max(n,max(u,v));//这个地方要处理一下 
      insert(u,v); insert(v,u);
    }
    for (int i=1;i<=n;i++)
    {
      if (!dfn[i]) Tarjan(root=i,0);
      if (deg>=2) cut[root]=1;//根节点的割点 
      deg=0;//不要忘记是多组数据 
    }
    for (int i = 1; i <= n; i++) {
      std::cout << cut[i] << std::endl;
    }
    for (int i=1;i<=n;i++)
      if (!vis[i]&&!cut[i])//不是割点 
      {
        T++; cnt=num=0;//T为连通块的标记 
        dfs(i);
        if (!num) ans1+=2,ans2*=cnt*(cnt-1)/2;//建两个 别忘记除以二 因为两个建立的出口没有差异 
        if (num==1) ans1++,ans2*=cnt;//建一个 
      }
    printf("Case %d: %d %lld\n",++cases,ans1,ans2);
    m=read();
  }
  return 0;
}

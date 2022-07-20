#include<bits/stdc++.h>
using namespace std;
inline int read(){
  int a=0;char c=getchar();
  while(c>57 or c<48){c=getchar();}
  while(47<c and c<58){
    a=a*10+c-48;
    c=getchar();
  }
  return a;
}
#define MN 500005
int n,m,u,v,cnt,fa[MN][21],w[MN],h[MN];
int Log[MN],top[MN],dep[MN],id[MN],U[MN],D[MN];
vector<int>edge[MN];
void dfs1(int x){
  for(int i=1;i<=19;++i)fa[x][i]=fa[fa[x][i-1]][i-1];
  for(int i=0;i<edge[x].size();++i){
    dep[edge[x][i]]=h[edge[x][i]]=dep[x]+1;
    dfs1(edge[x][i]);
    h[x]=max(h[x],h[edge[x][i]]);
    if(h[edge[x][i]]>h[w[x]])w[x]=edge[x][i];
  }
}
void dfs2(int x,int p){
  id[x]=++cnt;
  D[cnt]=x;
  U[cnt]=p;
  if(w[x]){top[w[x]]=top[x];dfs2(w[x],fa[p][0]);}
  for(int i=0;i<edge[x].size();++i)
    if(edge[x][i]!=w[x]){
      top[edge[x][i]]=edge[x][i];
      dfs2(edge[x][i],edge[x][i]);
    }
}
int rt;
#define ui unsigned int
ui S;
#define LL long long
inline ui get() {
  S ^= S << 13;
  S ^= S >> 17;
  S ^= S << 5;
  return S; 
}
inline int ask(register int x,register int k){
  cout << x << " " << k << endl;
  if(!k)return x;
  x=fa[x][Log[k]];k-=(1<<Log[k]);
  k-=dep[x]-dep[top[x]];x=top[x];
  if(k>=0) return U[id[x]+k];
  return D[id[x]-k];
}
int main(){
  n=read();m=read();scanf("%u",&S);
  Log[0]=-1;
  for(int i=1;i<=n;++i)Log[i]=Log[i>>1]+1;
  rt=1;
  for(int i=1;i<=n;++i){
    fa[i][0]=read();
    if(!fa[i][0])rt=i;
    else edge[fa[i][0]].push_back(i);
  }
  dep[rt]=1;dfs1(rt);
  top[rt]=rt;dfs2(rt,rt);
  LL ans=0;
  int lstans=0;
  for (int i = 1; i <= n; i++) {
    cout << h[i] << " ";
  }
  cout << endl;
  for (int i = 1; i <= n; i++) {
    cout << w[i] << " ";
  }
  cout << endl;
  for(int i=1;i<=m;++i){
    register int x=(get()^lstans)%n+1,k=(get()^lstans)%dep[x];
    lstans=ask(x,k);
    cout << lstans << endl;
    ans^=(LL)i*lstans;
  }
  printf("%lld\n",ans);
  return 0;
}

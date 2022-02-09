#include<bits/stdc++.h>
using namespace std;
int n,m,k,l[100002],r[100002],u[100002],d[100002],ans,f[100002],st[100002],top,ff[100002];
vector<int>a[100002],b[100002];
inline int read(){
  int num=0,f=1;
  char ch=getchar();
  while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
  while(isdigit(ch)){num=(num<<3)+(num<<1)+ch-'0';ch=getchar();}
  return num*f;
}
int main(){
  freopen("paint.in","r",stdin);
  freopen("paint.out","w",stdout);
  n=read();m=read();k=read();
  for(int i=1;i<=n;++i)a[i].resize(m+3);
  for(int i=1;i<=n;++i)b[i].resize(m+3);
  for(int i=1;i<=k;++i)d[i]=0x3f3f3f3f;
  for(int j=1;j<=k;++j)l[j]=0x3f3f3f3f;
  for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
      a[i][j]=read();
      // printf("%d ",a[i][j]);
      if(i>u[a[i][j]])u[a[i][j]]=i;
      if(i<d[a[i][j]])d[a[i][j]]=i;
      if(j<l[a[i][j]])l[a[i][j]]=j;
      if(j>r[a[i][j]])r[a[i][j]]=j;
    }
    // puts("");
  }
  if(n==1){
    for(int i=1;i<=m;++i){
      if(!f[a[1][i]])st[++top]=a[1][i],f[a[1][i]]++;
      else{
        while(st[top]!=a[1][i])f[st[top]]--,ff[st[top]]=1,--top;
      }
    }
    for(int i=1;i<=k;++i)ans+=!ff[i];
    printf("%d",ans);
    return 0;
  }
  for(int i=1;i<=k;++i){
    // printf("%d %d %d %d\n",u[i],d[i],l[i],r[i]);
    if(!u[i])continue;
    for(int x=d[i];x<=u[i];++x){
      for(int y=l[i];y<=r[i];++y){
        if(a[x][y]!=i)f[a[x][y]]=1;
      }
    }
  }
  for(int i=1;i<=k;++i)ans+=!f[i];
  printf("%d",ans);
  return 0;
}
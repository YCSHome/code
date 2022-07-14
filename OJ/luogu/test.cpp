#include <stdio.h>
#include<iostream>
#include <algorithm>
using namespace std ;
const int maxn = 1000016,maxe = 3000000 ;
struct node{
  int to,pre,val,from;
}e[maxe];
int x,y,n,e1,e2,cnt,num,h,t ;
int into[maxn],q[maxn],head[maxn] ;
inline void addedge(int x,int y,int w) 
{
  e[++cnt].to = y;e[cnt].from=x;
  e[cnt].pre = head[x] ;
  e[cnt].val=w; 
  head[x] =cnt;
}
int main(){
  scanf("%d%d%d",&n,&e1,&e2) ;
  for(int i=1;i<=e1;i++) {
    scanf("%d%d",&x,&y) ;
    addedge(x,y,0);into[y]++;
  } 
  for(int i=1;i<=n;i++) 
    if(into[i]==0) q[++t]=i;
  if(cnt%2==0) cnt++;
  for(int i=1;i<=e2;i++){
    scanf("%d%d",&x,&y);
    addedge(x,y,1);
    addedge(y,x,1);
  }
  while(h<t) {
    int u=q[++h] ; 
    for(int i=head[u];i;i=e[i].pre) {
      if(e[i].val==0) {
        into[e[i].to]--; 
        if(into[e[i].to]==0) q[++t]=e[i].to;
      } 
    }
    cout << u << endl;
    for(int i=head[u];i;i=e[i].pre)
      if(e[i].val==1) e[i^1].val=2;
  }
  for(int i=1;i<=cnt;i++)
    if(e[i].val==1) printf("%d %d\n",e[i].from,e[i].to);
  return 0 ;
}


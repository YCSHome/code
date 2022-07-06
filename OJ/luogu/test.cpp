#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<map>
#include<vector>
#include<memory.h>
#include<set> 
#include<cmath>

#define int long long

using namespace std;

struct house{
  int ind;
  int tim;
}h[1000005];

int n,m,t,ans=0,res=0;
priority_queue<int> pq;

bool cmp(house a,house b){
  return a.ind<b.ind;
}

signed main(){

  cin>>n>>m;

  for(int i=1;i<=n;i++){
    scanf("%lld%lld",&h[i].ind,&h[i].tim);
  }

  sort(h+1,h+n+1,cmp);
  h[0].ind=0;

  int tim=0;
  for(int i=1;i<=n;i++){

    tim+=h[i].ind-h[i-1].ind;
    pq.push(h[i].tim);
    ans++;
    tim+=h[i].tim;

    while(tim>m&&!pq.empty()){
      tim-=pq.top();
      pq.pop();
      ans--;
    }

    if(tim>m){
      break;
    }

    res=max(res,ans);

  }

  cout<<res<<endl;

  return 0;
}

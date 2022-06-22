#include<bits/stdc++.h>
using namespace std;
int p[100005];
vector<int> v[100005];
bool b[100005];
bool bb[100005];
int main(){
  freopen("dance.in","r",stdin);
  freopen("dance.out","w",stdout);
  long long n,k,m;
  cin >> n >> k >> m;
  for(int i = 1;i <= n;i++){
    p[i]=i;
  }
  for(int i = 1;i <= k;i++){
    int x,y;
    cin >>x >> y;
    swap(p[x],p[y]);
    v[p[x]].push_back(x);
    v[p[y]].push_back(y);
  }
  for(int i = 1;i <= n;i++){
      fill(b,b+100005,0);
      fill(bb,bb+100005,0);
      b[i]=1;
      int x= i;
    for(int j = 1;j <= m/k;j++){
        bb[x]=1;
        int s = 0;
      for(int kk = 0;kk < v[x].size();kk++){
        if(!b[v[x][kk]]){
          b[v[x][kk]]=1;
        }
        s=v[x][kk];
      }
      x=s;
      if(bb[s]){
        break;
      }
    }
      for(int kk = 0;kk < v[x].size()&&kk < m%k;kk++){
        if(!b[v[x][kk]]){
          b[v[x][kk]]=1;
        }
      }
      int sum = 0;
      for(int j = 1;j <= n;j++){
        if(b[j]){
          sum++;
        }
      }
      cout << sum << endl;
  }
}

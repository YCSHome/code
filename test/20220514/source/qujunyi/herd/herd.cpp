#include<bits/stdc++.h>
using namespace std;
bool b[30];
vector<int> v;
vector<int> vv;
vector<int> vvv[1000005];
string ss[1000005];
int s = 0;
void dfs(int x){
  if(x==v.size()){
    vvv[++s]=vv;
    return;
  }
  for(int i = 0;i < v.size();i++){
    if(!b[i]){
        b[i]=1;
        vv.push_back(v[i]);
        dfs(x+1);
        vv.pop_back();
        b[i]=0;
    }
  }
}
int main(){
  freopen("herd.in","r",stdin);
  freopen("herd.out","w",stdout);
  string a;
  cin >> a;
  for(int i = 0;i < a.size();i++){
    int p = a[i]-'a';
    if(!b[p]){
      v.push_back(p);
      b[p]=1;
    }
  }
  fill(b,b+30,0);
  dfs(0);
  int maxn = 1e9;
  for(int i = 1;i <= s;i++){
    for(int j = 0;j < v.size();j++){
      ss[i]+=(char)(vvv[i][j]+'a');
    }
    int p = 0,sum = 0;
    //cout << ss[i]<< endl;
    for(int j = 0;j < a.size();j++){
        //cout << a[j]<<" "<<p<<" "<<sum << endl;
      while(ss[i][p]!=a[j]){
        p++;
        if(p==ss[i].size()){
          p=0,sum++;
        }
      }
      p++;
      if(p==ss[i].size()){
        p=0,sum++;
      }
    }
    maxn=min(maxn,sum);
  }
  cout << maxn;
}

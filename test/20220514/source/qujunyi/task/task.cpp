#include<bits/stdc++.h>
using namespace std;
struct node{
  int x,y;
}a[100005],b[200005];
int si,sii;
bool cmp(node i,node j){
  return i.x < j.x;
}
bool Cmp(node i,node j){
  if(i.x-i.y == j.x-j.y){
    return i.x <j. x;
  }
  return (i.x-i.y)< (j.x-j.y);
}
int dp[105][300005];
int main(){
  freopen("task.in","r",stdin);
  freopen("task.out","w",stdout);
  int n;
  long long r;
  cin >> n >>r;
  for(int i = 1;i <= n;i++){
    int x,y;
    cin >> x >>y;
    if(y>=0){
      a[++si].x=x,a[si].y=y;
    }else{
      b[++sii].x=x,b[sii].y=y;
    }
  }
  sort(a+1,a+1+si,cmp);
  int sum = 0;
  for(int i = 1;i <= si;i++){
    if(a[i].x<=r){
        sum++;
      r+=a[i].y;
    }
  }
  for(int i = 0;i < 105;i++){
    for(int j = 0;j < 300005;j++){
      dp[i][j]=0;
    }
  }
  sort(b+1,b+1+sii,Cmp);
  for(int i = 1;i <= sii;i++){
    //cout <<b[i].x <<" " <<-b[i].y <<" "<< max(b[i].x,-b[i].y) << endl;
    for(int j = max(b[i].x,-b[i].y);j<=r;j++){
        //cout << i <<" "<< j << endl;
      dp[i][j]=max(dp[i-1][j+b[i].y]+1,dp[i][j]);
        if(i==sii&&dp[i][j]!=1e9){
          //cout <<dp[i][j]<<" "<< j <<" "<< b[i].y <<  endl;
        }
    }
  }
  int maxn = 0;
  for(int i = 0;i <= r;i++){
    maxn=max(maxn,dp[sii][i]);
  }
  if(sum+maxn==n){
    cout << "Yes";
  }else{
    cout << "No"<< endl;
  cout <<sum+maxn;
  }
}

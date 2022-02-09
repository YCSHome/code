#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1001000;
int n,a[maxn],l[maxn],r[maxn];
void read(int &x){
    char c=getchar();x=0;
    while(c<'0'||c>'9'){
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
}
signed main(){
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    read(n);
    for(int i=1;i<=n;i++){
        read(a[i]);
    }
    sort(a+1,a+1+n);
    int az=0;
    l[1]=0;l[2]=a[2]-a[1];
    for(int i=3;i<=n;i++){
        l[i]=1000000000000000000ll;
        while(az<i-1&&l[az]<a[i]-a[az]){
            l[i]=min(l[i],max(a[i]-a[az],l[az]*3/2));
            az++;
        }
        l[i]=min(l[i],max(a[i]-a[az],l[az]*3/2));
        l[i]=min(l[i],max(a[i]-a[az-1],l[az-1]*3/2));
        if(az!=i-1){
            l[i]=min(l[i],max(a[i]-a[az+1],l[az+1]*3/2));
            //l[i]=max(a[i]-a[az],l[az]*3/2);
        }
        //else{
            //l[i]=min(max(a[i]-a[az],l[az]*3/2),max(a[i]-a[az+1],l[az+1]*3/2));
        //}
    //    cout<<i<<" "<<az<<endl;
    }
    az=n;
    r[n]=0;r[n-1]=a[n]-a[n-1];
    for(int i=n-2;i>=1;i--){
        r[i]=1000000000000000000ll;
        while(az>i+1&&r[az]<a[az]-a[i]){
            r[i]=min(r[i],max(a[az]-a[i],r[az]*3/2));
            az--;
        }
        r[i]=min(r[i],max(a[az]-a[i],r[az]*3/2));
        r[i]=min(r[i],max(a[az+1]-a[i],r[az+1]*3/2));
        if(az!=i+1){
            r[i]=min(r[i],max(a[az-1]-a[i],r[az-1]*3/2));
            //r[i]=max(a[az]-a[i],r[az]*3/2);
        }
        //else{
            //r[i]=min(max(a[az]-a[i],r[az]*3/2),max(a[az-1]-a[i],r[az-1]*3/2));
        //}
    }
    int ans=1000000000000000000ll;
    for(int i=1;i<=n;i++){
        cout<<l[i]<<" "<<r[i]<<endl;
        ans=min(ans,max(l[i],r[i]));
    }
    cout<<ans;
    printf("\n%dms",clock());
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],n,m,k;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9') {if (ch=='-') f=-f;ch=getchar();}
    while(ch>='0' && ch<='9') {x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
int main() {
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    n=read();m=read();k=read();
    for (int i=1;i<=n;i++) {
        int x=read();
        a[x]++;
    }
    int ans=0;
    for (int i=1;i<=k;i++) if (!a[i]) ans++;
    cout<<ans<<endl;
    return 0;
}
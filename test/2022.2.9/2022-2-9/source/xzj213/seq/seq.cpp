#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,fa[maxn],s[maxn],m,Mod;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9') {if (ch=='-') f=-f;ch=getchar();}
    while(ch>='0' && ch<='9') {x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
int find(int x) {
    if (fa[x]==x) return x;
    int Fa=find(fa[x]);
    s[x]+=s[fa[x]];
    return fa[x]=Fa;
}
int main() {
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
    n=read();m=read();Mod=read();
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int i=1;i<=m;i++) {
        int l=read(),r=read(),k=read();
        int fx=find(l-1),fy=find(r);
        if (fx!=fy) {
            fa[fx]=fy;
            s[fx]=((k+s[r])%Mod-s[l-1]+Mod)%Mod;
        }
        else if ((s[r]-s[l-1])%Mod!=k) {cout<<i-1<<endl;return 0;}
    }
    cout<<m<<endl;
    return 0;
}
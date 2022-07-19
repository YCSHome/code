#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<' '<<x<<endl
/* --------------- fast io --------------- */ // begin
namespace Fread {
const int SIZE = 1 << 26;
char buf[SIZE], *S, *T;
inline char getchar() {
	if (S == T) {
		T = (S = buf) + fread(buf, 1, SIZE, stdin);
		if (S == T) return '\n';
	}
	return *S++;
}
} // namespace Fread
namespace Fwrite {
const int SIZE = 1 << 26;
char buf[SIZE], *S = buf, *T = buf + SIZE;
inline void flush() {
	fwrite(buf, 1, S - buf, stdout);
	S = buf;
}
inline void putchar(char c) {
	*S++ = c;
	if (S == T) flush();
}
struct NTR {
	~ NTR() { flush(); }
} ztr;
} // namespace Fwrite
#ifdef ONLINE_JUDGE
	#define getchar Fread :: getchar
	#define putchar Fwrite :: putchar
#endif
namespace Fastio {
struct Reader {
	template<typename T>
	Reader& operator >> (T& x) {
		char c = getchar();
		T f = 1;
		while (c < '0' || c > '9') {
			if (c == '-') f = -1;
			c = getchar();
		}
		x = 0;
		while (c >= '0' && c <= '9') {
			x = (x * 10 + (c - '0'));
			c = getchar();
		}
		x *= f;
		return *this;
	}
	Reader& operator >> (char& c) {
		c = getchar();
		while (c == '\n' || c == ' ') c = getchar();
		return *this;
	}
	Reader& operator >> (char* str) {
		int len = 0;
		char c = getchar();
		while (c == '\n' || c == ' ') c = getchar();
		while (c != '\n' && c != ' ') {
			str[len++] = c;
			c = getchar();
		}
		str[len] = '\0';
		return *this;
	}
	Reader(){}
} cin;
const char endl = '\n';
struct Writer {
	template<typename T>
	Writer& operator << (T x) {
		if (x == 0) { putchar('0'); return *this; }
		if (x < 0) { putchar('-'); x = -x; }
		static int sta[45];
		int top = 0;
		while (x) { sta[++top] = x % 10; x /= 10; }
		while (top) { putchar(sta[top] + '0'); --top; }
		return *this;
	}
	Writer& operator << (char c) {
		putchar(c);
		return *this;
	}
	Writer& operator << (char* str) {
		int cur = 0;
		while (str[cur]) putchar(str[cur++]);
		return *this;
	}
	Writer& operator << (const char* str) {
		int cur = 0;
		while (str[cur]) putchar(str[cur++]);
		return *this;
	}
	Writer(){}
} cout;
} // namespace Fastio
#define cin Fastio :: cin
#define cout Fastio :: cout
#define endl Fastio :: endl
/* --------------- fast io --------------- */ // end

#define maxn 300010
typedef unsigned long long ull;
int n;
ull pw[maxn];
struct prpr{
	int len;
	ull s;
	prpr(int ll=0,int ss=0):len(ll),s(ss){}
}t1[maxn<<2],t2[maxn<<2];
prpr operator+(prpr a,prpr b){
	return prpr(a.len+b.len,pw[b.len]*a.s+b.s);
}
void build(int l,int r,int x=1){
	t1[x].len=t2[x].len=r-l+1;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(l,mid,x<<1),build(mid+1,r,x<<1|1);
	t1[x]=t1[x<<1]+t1[x<<1|1];
	t2[x]=t2[x<<1|1]+t2[x<<1];
}
void change(int pos,int l=1,int r=n,int x=1){
	if(l==r){
		t1[x].s=t2[x].s=1;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)change(pos,l,mid,x<<1);
	else change(pos,mid+1,r,x<<1|1);
	t1[x]=t1[x<<1]+t1[x<<1|1];
	t2[x]=t2[x<<1|1]+t2[x<<1];
}
prpr ask1(int x,int y,int l=1,int r=n,int o=1){
	if(x<=l&&r<=y)return t1[o];
	int mid=(l+r)>>1;
	prpr ans;
	if(x<=mid)ans=ask1(x,y,l,mid,o<<1);
	if(y>mid)ans=ans+ask1(x,y,mid+1,r,o<<1|1);
	return ans;
}
prpr ask2(int x,int y,int l=1,int r=n,int o=1){
	if(x<=l&&r<=y)return t2[o];
	int mid=(l+r)>>1;
	prpr ans;
	if(y>mid)ans=ask2(x,y,mid+1,r,o<<1|1);
	if(x<=mid)ans=ans+ask2(x,y,l,mid,o<<1);
	return ans;
}
int x,len;
signed main(){
	cin>>n;pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*131;
	build(1,n);
	for(int i=1;i<=n;i++){
		cin>>x;
		change(x);
		len=min(x-1,n-x);
		if(len==0)continue;
    if (n >= 300){ 
        cout << x- len << " " << x - 1 << " " << x + 1 << " " << x + len << endl;
        cout << ask1(x - len, x - 1).s << " " << ask2(x + 1, x + len).s << endl;
    }
		if(ask1(x-len,x-1).s!=ask2(x+1,x+len).s){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
}

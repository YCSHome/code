#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
map < pair < int , int > , int > M;
string s;
int suma[1010100],sumb[1010100],sumc[1010100];

int main(){
    long long ans = 0;
	cin>>s;M[mp(0,0)] = 1;
	for (int i=0;i<s.size();i++)
	  suma[i+1]+= (s[i]=='A') + suma[i],
	  sumb[i+1]+= (s[i]=='B') + sumb[i],
	  sumc[i+1]+= (s[i]=='C') + sumc[i];//前缀和
	int n = s.size();
	for (int i=1;i<=n;i++){
		int A = suma[i]-sumb[i] , B = sumb[i] - sumc[i];
		ans+=(long long)M[mp(A,B)]++;//当前的二元组可以喝里面的每一个配成一对，然后在累加上
	}
	printf("%lld",ans);
	return 0;
}

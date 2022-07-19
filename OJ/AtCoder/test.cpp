#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

map<long long, int> mp;
char s[N];
long long jx, i1, o1;
int n;
int ans = 0;

int main(){
 	cin >> n;
	cin >> s + 1; 
 	mp.clear();
 	mp[0] = 0;
 	for(int i = 1; i <= n; i++){
 		jx += s[i] == 'J' ? 1 : 0;
 		i1 += s[i] == 'I' ? 1 : 0;
 		o1 += s[i] == 'O' ? 1 : 0; 
 		long long hah = 100000 * (jx - i1) + (jx - o1);
 		if(mp.find(hah) != mp.end()) {
      ans = max(ans, i - mp[hah]);
    } else {
      cout << i << " ";
      mp[hah] = i;
    }
    cout << jx << " " << i1 << " " << o1 << endl;
	}
 	cout << ans;
 	return 0;
}

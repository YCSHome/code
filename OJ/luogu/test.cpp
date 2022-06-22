#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	vector<int> a = {1, 2};
	int tot = 0;
	do {
		int ans = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = i + 1; j < 2; j++) {
				if (a[i] > a[j]) {
					ans++;
				}
			}
		}
		tot += ans;
	} while (next_permutation(a.begin(), a.end()));
	cout << (double)tot / 2.0 << endl;
	return 0;
}

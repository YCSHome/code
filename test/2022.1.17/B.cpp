#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 20;

int a[MAXN], n;
bool prime[100], used[MAXN];

void sieve(int MAX) {
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (int i = 2; i <= MAX; i++) {
        if (prime[i]) {
            for (int k = 2; k * i <= MAX; k++) {
                prime[i * k] = false;
            }
        }
    }
}

void dfs(int c, int p) {
    if (c > n) {
        if (prime[a[n] + a[1]]) {
            for (int i = 1; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << a[n] << endl;
        }
        return ;
    }
    for (int i = p; i <= n; i += 2) {
        if (prime[i + a[c - 1]] && !used[i]) {
            used[i] = true;
            a[c] = i;
            dfs(c + 1, p ^ 3);
            used[i] = false;
        }
    }
}

int main() {
    sieve(50);
    a[1] = 1;
    used[1] = true;
    for (int t = 1; cin >> n; t++) {
        if (t != 1) {
            cout << endl;
        }
        cout << "Case" << " " << t << ":" << endl;
        dfs(2, 2);
    }
    return 0;
}

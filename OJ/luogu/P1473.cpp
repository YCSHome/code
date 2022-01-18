#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAXN = 1001;

int n;
int op[MAXN];

bool get() {
    int ans = 0, t;
    for (int i = 1; i <= n; i++) {
        if (op[i] == 0) {
            continue;
        }
        t = i;
        for (int j = i + 1; j <= n; j++) {
            if (op[j] != 0) break;
            t = t * 10 + j;
        }
        if (op[i] == 1) ans += t;
        else ans -= t;
    }
    if (ans == 0) return true;
    return false;
}

void dfs(int c) {
    if (c > n) {
        if (get()) {
            cout << 1;
            for (int i = 2; i <= n; i++) {
                if (op[i] == 1) {
                    cout << "+";
                } else if (op[i] == 2) {
                    cout << "-";
                } else if (op[i] == 0) {
                    cout << " ";
                }
                cout << i;
            }
            cout << endl;
        }
        return ;
    }
    for (int i = 0; i <= 2; i++) {
        op[c] = i; dfs(c + 1);
    }
}

int main() {
    cin >> n; 
    op[1] = 1;
    dfs(2);
    return 0;
}

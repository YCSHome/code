#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = l; i <= r; i++)
#define dep(i, r, l) for (int i = r; i >= l; i--)

const int N = 1e6 + 10;

int m, n = 1, x[N], f[N], g[N], ans = INT_MAX;

void read (int &x) {
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9')
        x = x * 10 + (c ^ 48), c = getchar();
}

void DPF (int l, int r, int u, int v) {
    if (r <= l) {
        rep(j, u, min(v, l - 1))
            f[l] = min(f[l], max(x[l] - x[j], (int)ceil(3.0 * f[j] / 2.0)));
        return;
    }
    int mid = l + r >> 1, p = mid;
    rep(j, u, min(v, mid - 1)) {
        int val = max(x[mid] - x[j], (int)ceil(3.0 * f[j] / 2.0));
        if (val < f[mid]) f[mid] = val, p = j;
    }
    DPF(l, mid - 1, u, p), DPF(mid + 1, r, p, v);
}

void DPG (int l, int r, int u, int v) {
    if (r <= l) {
        rep(j, max(u, l + 1), v)
            g[l] = min(g[l], max(x[j] - x[l], (int)ceil(3.0 * g[j] / 2.0)));
        return;
    }
    int mid = l + r >> 1, p = mid;
    rep(j, max(u, mid + 1), v) {
        int val = max(x[j] - x[mid], (int)ceil(3.0 * g[j] / 2.0));
        if (val < g[mid]) g[mid] = val, p = j;
    }
    DPG(l, mid - 1, u, p), DPG(mid + 1, r, p, v);
}

int main () {

    // freopen("bomb.in", "r", stdin);

    read(m);
    rep(i, 1, m) read(x[i]);

    sort(x + 1, x + m + 1);
    rep(i, 1, m) if (x[i] != x[n]) x[++n] = x[i];

    // memset(f, 0x7f, sizeof f), f[1] = 0;
    // rep(i, 2, n) rep(j, 1, i - 1)
    //     f[i] = min(f[i], max(x[i] - x[j], (int)ceil(3.0 * f[j] / 2)));
    // memset(g, 0x7f, sizeof g), g[n] = 0;
    // dep(i, n - 1, 1) dep(j, n, i + 1)
    //     g[i] = min(g[i], max(x[j] - x[i], (int)ceil(3.0 * g[j] / 2)));

    memset(f, 0x3f, sizeof f), f[1] = 0;
    memset(g, 0x3f, sizeof g), g[n] = 0;
    DPF(2, n, 1, n - 1), DPG(1, n - 1, 2, n);

    rep(i, 1, n) ans = min(ans, max(f[i], g[i]));
    cout << ans << endl;

    return 0;
}
void dfs(int c, double summ)
{
    if (c > n) {
        ans = max(ans, summ);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] ^= 1;
            // 我觉得用INT_MAX没问题
            double s = INT_MAX;
            s = min(s, double(X[i] - X1));
            s = min(s, double(X2 - X[i]));
            s = min(s, double(Y[i] - Y1));
            s = min(s, double(Y2 - Y[i]));
            // 优先遍历所有点,取最小值
            for (int j = 1; j < c; j++)
            {
                s = min(s, get_len(i, p[j]) - len[j]);
            }
            s = max(s, double(0));
            len[c] = s;
            p[c] = i;
            dfs(c + 1, summ + s * s * pi);

            used[i] ^= 1;
        }
    }
}

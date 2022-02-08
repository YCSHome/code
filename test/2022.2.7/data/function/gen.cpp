#include <bits/stdc++.h>

#define For(i, j, k) for (int i = j; i <= k; i++)

using namespace std;

typedef long long LL;

const int TASK = 6; 
const int CASE = 5;
const int mx = 1e9;
const int N = 5e5 + 10;
const int limN[TASK] = {300, 300, 100000, 100000, 500000, 500000};
const int limQ[TASK] = {100000, 100000, 100000, 100000, 500000, 500000};
const int limX[TASK] = {1000, mx, 100000, 100000, mx, mx};

int randint(int l, int r) {
	assert(l <= r);
	return rand() % (r - l + 1) + l;
}

int A[N], n, q;
int qy[N], cnt[N];
vector<int> qx[N];

namespace Solver {

	LL S[N];
	int L[N], st[N];
	int c;

	LL calc(int x, int y, int u) {
		return S[x] - S[u] + 1ll * (y + u) * A[u];
	}

	void work(int lim) {
		c = 0, S[0] = 0;

		For(i, 1, n) S[i] = S[i - 1] + A[i];
		L[0] = lim + 5, S[0] = 1ll << 60;
		int mxc = 0;

		For(i, 1, n) {
			while (c && calc(i, L[c - 1] - 1, st[c]) >= calc(i, L[c - 1] - 1, i)) --c;
			if (c) {
				int l = L[c], r = L[c - 1] - 1;
				while (l < r) {
					int mid = (l + r) >> 1;
					if (calc(i, mid, st[c]) < calc(i, mid, i)) r = mid;
					else l = mid + 1;
				}
				L[c] = l;
				assert(L[c] < L[c - 1]);
			}
			st[++c] = i, L[c] = 1 - i;
			while (cnt[i]) {
				int x = randint(1, c);
				LL p = min(lim, i + randint(L[x], L[x - 1] - 1));
				if (rand() % 3 && p == lim) continue;
				qx[i].push_back(p);
				--cnt[i];
			}
			mxc = max(mxc, c);
		}
		cerr << "maxc = " << mxc << endl;
	}
};

// subtask4 : random a_i
// subtask5 : same x

int main() {

	srand(time(0));

	For(t, 1, TASK) {

		char cmd[100];
		sprintf(cmd, "mkdir subtask%d", t);
		system(cmd);

		For(c, 1, CASE) {
			
			if (t == 4 && c > 2) continue;

			sprintf(cmd, "subtask%d/%d.in", t, c);
			freopen(cmd, "w", stdout);

			n = limN[t - 1] - rand() % 10, q = limQ[t - 1] - rand() % 10;
			int lim = limX[t - 1];

			switch (c) {
				case 1: // small random
					For(i, 1, n) A[i] = randint(0, 100);
					break;
				case 2: // full random
					For(i, 1, n) A[i] = randint(0, mx);
					break;
				case 3: // increasing
					For(i, 1, n) A[i] = A[i - 1] + randint(0, mx / n);
					break;
				case 4: // random + increasing
					For(i, 1, n) A[i] = i & 1 ? randint(0, lim) : i / 2;
					break;
				case 5: // decreasing + increasing
					A[1] = lim;
					For(i, 2, n) A[i] = i & 1 ? A[i - 2] - randint(0, lim / n) : i / 2;
					break;
			}

			For(i, 1, q) qy[i] = t == 5 ? (i - 1) % n + 1 : randint(1, n), ++cnt[qy[i]];
			random_shuffle(qy + 1, qy + q + 1);
			Solver::work(lim);

			printf("%d\n", n);
			For(i, 1, n) printf("%d%c", A[i], i == n ? '\n' : ' ');
			printf("%d\n", q);

			if (t == 5) {
				LL sum = 0;
				For(i, 1, q) sum += qx[qy[i]].back(), qx[qy[i]].pop_back();
				int x = sum / q;
				For(i, 1, q) printf("%d %d\n", x, qy[i]);
			} else {
				For(i, 1, q) printf("%d %d\n", qx[qy[i]].back(), qy[i]), qx[qy[i]].pop_back();
			}

			sprintf(cmd, "time ./function < subtask%d/%d.in > subtask%d/%d.out", t, c, t, c);
			freopen("tmp", "w", stdout);
			system(cmd);
		
		}
	}

	return 0;
}

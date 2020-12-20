#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define xLOCAL
const int MaxN = 5010;

struct interval {
	int l, r, num, ans;
	interval(): l(0), r(0), num(0), ans(0) {}
	bool operator < (const interval &xx) const {
		if (r < xx.r) return true;
		if (r > xx.r) return false;
		if (l < xx.l) return true;
		return false;
	};
};

bool cmp(const interval &a, const interval &b) {
	return a.num < b.num;
}

int n;
bool flag[MaxN];
interval itvX[MaxN], itvY[MaxN];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);

	bool done;
	while (true) {
		scanf("%d", &n);
		if (!n) break;
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d%d", &itvX[i].l, &itvY[i].l, &itvX[i].r, &itvY[i].r);
			itvX[i].num = itvY[i].num = i;
		}
		sort(itvX, itvX + n);
		sort(itvY, itvY + n);

		//make interval of X
		memset(flag, 0, sizeof(flag));
		for (int i = 0; i < n; ++i) {
			done = false;
			int j = itvX[i].l;
			while (!done) {
				if (!flag[j]) {
					flag[j] = true;
					itvX[i].ans = j;
					done = true;
				}
				if (j == itvX[i].r) break;
				else ++j;
			}
			if (!done) break;
		}
		if (!done) {
			printf("IMPOSSIBLE\n");
			continue;
		}

		memset(flag, 0, sizeof(flag));
		//make interval of Y
		for (int i = 0; i < n; ++i) {
			done = false;
			int j = itvY[i].l;
			while (!done) {
				if (!flag[j]) {
					flag[j] = true;
					itvY[i].ans = j;
					done = true;
				}
				if (j == itvY[i].r) break;
				else ++j;
			}
			if (!done) break;
		}
		if (!done) {
			printf("IMPOSSIBLE\n");
			continue;
		}

		sort(itvX, itvX + n, cmp);
		sort(itvY, itvY + n, cmp);
		for (int i = 0; i < n; ++i)
			printf("%d %d\n", itvX[i].ans, itvY[i].ans);
	}
	return 0;
}

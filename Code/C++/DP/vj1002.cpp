#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 1 << 30;
const int maxn = 110 * 1060;

#define xfilestream

int L, s, t, m, p, q, ans = inf;
int a[200], f[maxn];
bool b[maxn];

int main() {
#ifdef filestream
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d%d%d", &L, &s, &t, &m);
	memset(a, 0, sizeof(a));
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	if (s == t) {
		int cnt = 0;
		for (int i = 0; i < m; i++)
			if (!(a[i] % s))
				cnt++;
		printf("%d\n", cnt);
		return 0;
	}
	a[m] = L;
	sort(a, a + m);
	memset(b, 0, sizeof(b));
	
	if (a[0] > 105) {
		b[106] = true;
		p = 105;
	}
	else {
		b[a[0]] = true;
		p = a[0];
	}
	for (int i = 1; i <= m; i++) {
		int tmp = a[i]-a[i-1];
		if (tmp > 105) {
			p += 105;
			b[p] = true;
		}
		else {
			p += tmp;
			b[p] = true;
			
		}
		if (i == m - 1)
			q = p;
	}
	fill(f, f + p + 1, inf);
	f[0] = 0;
	b[p] = false;
	for (int i = s; i <= p; i++) {
		int minn = inf;
		for (int j = i - s; i-t>=0 && j >= i - t; j--)
			minn = min(minn, f[j]);
		if (minn != inf) {
			f[i] = minn;
			f[i] += b[i] ? 1 : 0;
		}
	}
	for (int i = q; i <= p; i++)
		ans = min(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}

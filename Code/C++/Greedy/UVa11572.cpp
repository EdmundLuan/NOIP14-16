#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;

#define xLOCAL
#define MaxN 1000005

set<int> f;
int n, T, l, r;
int a[MaxN];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);

	int ans, x;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		l = 0; r = 0; ans = 1;
		f.clear();
		while (r < n) {
			while (r < n && !f.count(a[r])) f.insert(a[r++]);
			ans = max(ans, r - l);
			f.erase(a[l++]);
		}
		printf("%d\n", ans);
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int n, m, maxa = 0, sum = 0, a[100010], l, r, mid;

bool work(int mi) {
	int p = 0, groupnum = 0, cnt;
	while (p < n && groupnum < m) {
		groupnum++; cnt = 0;
		while (cnt + a[p] <= mi && p < n) {
			cnt += a[p]; p++;
		}
	}
	if (p < n)
		return false;
	return true;
}

int main() {
	freopen("input.txt","r",stdin);
	cin >> n >> m;
	sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
		maxa = max(maxa, a[i]);
	}
	l = maxa; r = sum;
	while (l < r) {
		mid = (l + r) / 2;
		if (work(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << l << endl;
	fclose(stdin);
	return 0;
}

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct binarytree {
	int l, r, data;
} tree[500];

int n, m, ans;
int lson[500];
int f[500][500];


void init() {
	memset(lson, 0, sizeof(lson));
	for (int i = 0; i <= n; i++) {
		tree[i].data = tree[i].l = tree[i].r = 0;
	}
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		tree[i].data = y;
		if (!lson[x])
			tree[x].l = i;
		else
			tree[lson[x]].r = i;
		lson[x] = i;
	}
}

int dp(int x, int y) {
	if (f[x][y])
		return f[x][y];
	if(!y)
		return 0;
	if (!tree[x].l && !tree[x].r) {
			return tree[x].data;
	}
	if (!tree[x].l && tree[x].r) {
		f[x][y] = max(f[x][y], dp(tree[x].r, y));
		f[x][y] = max(dp(tree[x].r, y - 1) + tree[x].data, f[x][y]);
		return f[x][y];
	}
	if (!tree[x].r && tree[x].l) {
		f[x][y] = max(f[x][y], dp(tree[x].l, y - 1) + tree[x].data);
		return f[x][y];
	}
	else {
		f[x][y] = max(f[x][y], dp(tree[x].r, y));
		for (int k = 1; k <= y; k++) {
			f[x][y] = max(f[x][y], dp(tree[x].l, k - 1) + dp(tree[x].r, y - k) + tree[x].data);
		}
		return f[x][y];
	}
}

int main() {
	//freopen("input.txt","r",stdin);
	cin >> n >> m;
	init();
	ans = dp(tree[0].l, m);
	printf("%d\n", ans);
	//fclose(stdin);
	return 0;
}

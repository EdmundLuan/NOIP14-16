#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

struct TREE {
	int l, r, data;
} tree[101];

int n, q, ans;
int matrix[101][101], f[101][101];
bool vis[101] = {0};

void init() {
	for (int i = 0; i <= n; i++) {
		tree[i].l = 0; tree[i].r = 0;
		tree[i].data = 0;
	}
}

void make_tree(int x) {
	vis[x] = true;
	for (int i = 1; i <= n; i++) {
		if (matrix[x][i] && !vis[i]) {
			if (!tree[x].l)
				tree[x].l = i;
			else
				tree[x].r = i;
			tree[i].data = matrix[x][i];
			make_tree(i);
		}
	}
}

int dp(int root, int q) {
	int tmp = 0;
	if (f[root][q])
		return f[root][q];
	if (!q)
		return 0;
	if (q == 1)
		return tree[root].data;
	for (int i = 0; i < q; i++) {
		tmp = max(tmp, tree[root].data + dp(tree[root].l, i) + dp(tree[root].r, q - 1 - i));
	}
	f[root][q] = tmp;
	return f[root][q];
}

int main() {
	//freopen("input.txt","r",stdin);
	cin >> n >> q;
	memset(f, 0, sizeof(f));
	memset(matrix, 0, sizeof(matrix));
	init();
	for (int i = 1; i < n; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		matrix[x][y] = z;
		matrix[y][x] = z;
	}
	tree[1].data = 0;
	make_tree(1);
	ans = dp(1, q + 1);
	printf("%d\n", ans);
	//fclose(stdin);
	return 0;
}

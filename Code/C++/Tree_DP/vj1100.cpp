#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n, ans;
long long f[50][50];
int w[50], root[50][50];

void init() {
	memset(w, 0, sizeof(w));
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	memset(f, -1, sizeof(f));
	memset(root, -1, sizeof(root));
}

long long dp(int left, int right) {
	int rootlr = -1;
	long long tmp = -1;
	if (f[left][right] >= 0) {
		tmp = f[left][right];
		rootlr = root[left][right];
	}
	else if (left > right) {
		tmp = 1;
	}
	else if (left == right) {
		tmp = w[left];
		rootlr = left;
	}
	else {
		for (int i = left; i <= right; i++) {
			long long dl = dp(left, i - 1), dr = dp(i + 1, right);
			if (tmp < dl * dr + w[i]) {
				tmp = dl * dr + w[i];
				rootlr = i;
			}
		}
	}
	f[left][right] = tmp;
	root[left][right] = rootlr;
	return tmp;
}

void preorder_traversal(int l, int r) {
	if (l <= r) {
		printf("%d ", root[l][r]);
		preorder_traversal(l, root[l][r] - 1);
		preorder_traversal(root[l][r] + 1, r);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	init();
	ans = dp(1, n);
	printf("%d\n", ans);
	preorder_traversal(1, n);
	cout << endl;
	fclose(stdin);
	return 0;
}

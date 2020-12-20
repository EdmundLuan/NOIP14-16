#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy[8] = { -1, 1, -1, 0, 1, -1, 0, 1};

int t, n, m, ans;
int f[10][10];
bool flag[10][10];

void init() {
	ans = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++) {
			flag[i][j] = true;
		}
}

void cpy(bool (*tmp)[10]) {
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			tmp[i][j] = flag[i][j];
}

void restore(bool (*tmp)[10]) {
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			flag[i][j] = tmp[i][j];
}

void dfs(int x, int y, int sum) {
	bool tmp[10][10];
	bool ff = true;
	if (x > n) {
		ans = max(ans, sum);
		return;
	}
	if (y > m) {
		dfs(x + 1, 1, sum);
		return;
	}
	/*
	if (!flag[x][y]){
		dfs(x, y + 1, sum);
		return;
	}*/
	for (int i = 0; i < 8; i++)
		ff &= flag[x + dx[i]][y + dy[i]];
	if (!ff) {
		dfs(x, y + 1, sum);
		return;
	}
	dfs(x, y + 1, sum);
	cpy(tmp);
	for (int i = 0; i < 8; i++)
		flag[x + dx[i]][y + dy[i]] = false;
	flag[x][y] = false;
	dfs(x, y + 1, sum + f[x][y]);
	restore(tmp);
	flag[x][y] = true;
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--) {
		scanf("%d%d", &n, &m);
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &f[i][j]);
		init();
		dfs(1, 1, 0);
		printf("%d\n", ans);
	}
	fclose(stdin);
	return 0;
}

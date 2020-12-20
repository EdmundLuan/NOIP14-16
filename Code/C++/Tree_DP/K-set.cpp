#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct EDGE {
	int to, next;
} edge[20002];

int n, k, ans, index;
int head[10001], f[10001][3], g[10001];

void addedge(int x, int y) {
	edge[index++].to = y;
	edge[index].next = head[x];
	head[x] = index;
	edge[index++].to = x;
	edge[index].next = head[y];
	head[y] = index;
}

void init() {
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		addedge(x, y); addedge(y, x);
	}
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
	memset(head, -1, sizeof(head));
}

void dp(int u, int fa) {
	int sum = 0, v, cnt = 0;
	//h=head[u];
	for (int i = head[u]; i != -1; i = edge[i].next) {
		v = edge[i].to;
		if (v == fa)
			continue;
		dp(v, u);
	}

	f[u][0] = 0;
	for (int i = head[u]; i != -1; i = edge[i].next) {
		v = edge[i].to;
		if (v == fa)
			continue;
		f[u][0] = max(f[v][1], f[v][0]);
		sum += f[v][2];
		g[++cnt] += f[v][2] - f[v][0];
	}

	if (cnt > 0) {
		sort(g + 1, g + cnt + 1);
		f[u][1] = ++sum;
		for (int i = 1; i <= cnt - k; i++)
			f[u][1] -= g[i];
		for (int i = cnt - k + 1; i <= cnt; i++) {
			if (g[i] < 0)
				f[u][1] -= g[i];
		}

		f[u][2] = sum;
		for (int i = 1; i <= cnt - k + 1; i++)
			f[u][2] -= g[i];
		for (int i = cnt - k + 2; i <= cnt; i++) {
			if (g[i] < 0)
				f[u][2] -= g[i];
		}
	}
	else {
		f[u][1] = 1; f[u][2] = 1;
	}
	if (!k)
		f[u][2] = 0;
}

int main() {
	freopen("input.txt","r",stdin);
	cin >> n >> k;
	init();
	dp(1, 0);
	ans = max(f[1][0], f[1][1]);
	printf("%d\n", ans);
	fclose(stdin);
	return 0;
}

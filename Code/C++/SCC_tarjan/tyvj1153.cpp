#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>

using namespace std;

const int inf = INT_MAX;

int ans = 0, n, p, r, cnt = 0, top = 0, indegree;
bool graph[8001][8001] = {0}, vis[8001] = {0}, reserve[8001], in_stk[8001];
int cost[8001], low[8001], dfn[8001], stk[8001];

void init() {
	scanf("%d%d", &n, &p);
	fill(cost, cost + n + 1, inf);
	fill(reserve, reserve + n + 1, 1);
	fill(in_stk, in_stk + n + 1, 0);
	for (int i = 0; i < p; i++) {
		int x;
		scanf("%d", &x);
		scanf("%d", &cost[x]);
	}
	cin >> r;
	for (int i = 0; i < r; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		graph[x][y] = true;
	}
}

void change(int u, int v) {
	for (int i = 1; i <= n; i++) {
		if (graph[v][i]) {
			graph[v][i] = false;
			graph[u][i] = true;
		}
		if (graph[i][v]) {
			graph[i][v] = false;
			graph[i][u] = true;
		}
	}
}

void tarjan(int u) {
	int v;
	vis[u] = true;
	low[u] = dfn[u] = ++cnt;
	stk[++top] = u;
	in_stk[u] = true;
	for (v = 1; v <= n; v++) {
		if (v == u)
			continue;
		if (!graph[u][v])
			continue;
		if (!vis[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (in_stk[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		while (u != stk[top]) {
			v = stk[top--];
			in_stk[v] = false;
			reserve[v] = false;
			change(u, v);
			cost[u] = min(cost[u], cost[v]);
		}
		in_stk[u] = false;
		reserve[u] = true;
		top--;
	}
}

int main() {
	init();
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			tarjan(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!reserve[i])
			continue;
		indegree = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			if (graph[j][i])
				indegree++;
		}
		if (!indegree) {
			if (cost[i] == inf) {
				printf("NO\n%d\n", i);
				return 0;
			}
			ans += cost[i];
		}
	}
	printf("YES\n%d\n", ans);
	return 0;
}

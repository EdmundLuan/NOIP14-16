#include<stdio.h>
struct info {
	int s;
	int e;
	int t;
};
struct info edge[5602];
int n, m, dist[600];
int bf() {
	int i, j, k, u, v, w;
	for (i = 2; i <= n; i++)
		dist[i] = 99999;
	for (i = 1; i < n; i++) {
		k = 1;
		for (j = 1; j <= m; j++) {
			u = edge[j].s; v = edge[j].e; w = edge[j].t;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				k = 0;
			}
		}
		if (k)
			break;
	}
	for (i = 1; i <= m; i++) {
		u = edge[i].s; v = edge[i].e; w = edge[i].t;
		if (dist[u] + w < dist[v])
			return (0);
	}
	return (1);
}
int main() {
	int i, j, F, w, ki, st, en, ti;
	scanf("%d", &F);
	for (i = 1; i <= F; i++) {
		ki = 0;
		scanf("%d%d%d", &n, &m, &w);
		for (j = 1; j <= m; j++) {
			scanf("%d%d%d", &st, &en, &ti);
			ki++;
			edge[ki].s = st;
			edge[ki].e = en;
			edge[ki].t = ti;
			ki++;
			edge[ki].s = en;
			edge[ki].e = st;
			edge[ki].t = ti;
		}
		for (j = 1; j <= w; j++) {
			ki++;
			scanf("%d%d%d", &st, &en, &ti);
			edge[ki].s = st;
			edge[ki].e = en;
			edge[ki].t = -ti;
		}
		m = ki;
		if (bf() == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

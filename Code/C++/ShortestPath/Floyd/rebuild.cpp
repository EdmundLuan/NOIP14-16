#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int inf = 2147483647;

int n, m, x, y, z, k = 0, Q;
int t[210],  dist[210][210];

void ed() {
	fclose(stdin);
	fclose(stdout);
	exit(0);
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		scanf("%d", &t[i]);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dist[i][j] = inf;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		dist[x][y] = z;
		dist[y][x] = z;
	}

}

int main() {
	freopen("input.txt", "r", stdin);
	init();
	cin >> Q;
	while (Q--) {
		scanf("%d%d%d", &x, &y, &z);
		if (z < t[x] || z < t[y]) {
			printf("-1\n");
			continue;
		}
		while (k < n && t[k] <= z) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					if (dist[i][k] != inf && dist[k][j] != inf)
						dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			k++;
		}
		if (dist[x][y] == inf)
			printf("-1\n");
		else
			printf("%d\n", dist[x][y]);
	}
	ed();
}

/*Tarjan LCA ¿ÎœﬂÀ„∑®*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <cctype>
#include <algorithm>
using namespace std;

const int maxl = 40010;

struct EDGE {
	int end, weight;
	int next;
} edge[2*maxl];

int n, m, index, t;
int father[maxl], x[250], y[250], z[250], dist[maxl], head[maxl];
bool vst[maxl];

void read(int &x) {
	char chr = getchar();
	x = 0;
	while (!isdigit(chr))
		chr = getchar();
	while (isdigit(chr)) {
		x *= 10; x += chr - 48;
		chr = getchar();
	}
}

void addedge(const int &u, const int &v, const int &w) {
	edge[index].end = v;
	edge[index].weight = w;
	edge[index].next = head[u];
	head[u] = index++;
}

void init() {
	int u, v, w;
	read(n); read(m); index = 0;
	fill(z, z + m, 0);
	dist[1] = 0;
	//fill(dist, dist + n + 1, 0);
	fill(head, head + n + 1, -1);
	fill(vst, vst + n + 1, 0);
	for (int i = 1; i < n; i++) {
		read(u); read(v); read(w);
		addedge(u, v, w);
		addedge(v, u, w);
	}
	for (int i = 0; i < m; i++) {
		read(x[i]); read(y[i]);
	}
}

int findset(const int xx) {
	return father[xx] == xx ? xx: father[xx] = findset(father[xx]);
}

void refresh(const int &xx) {
	for (int i = 0; i < m; i++) {
		if (xx == x[i] && vst[y[i]])
			z[i] = findset(y[i]);
		if (xx == y[i] && vst[x[i]])
			z[i] = findset(x[i]);
	}
}

void tarjan(int k) {
	vst[k] = true;
	father[k] = k;
	refresh(k);
	for (int i = head[k]; i != -1; i = edge[i].next) {
		int v = edge[i].end, w = edge[i].weight;
		if (!vst[v]) {
			dist[v] = dist[k] + w;
			tarjan(v);
			father[v] = k;
		}
	}
}

int main() {
	/*freopen("input.txt", "r", stdin);*/
	read(t);
	while (t--) {
		init();
		tarjan(1);
		for (int i = 0; i < m; i++)
			printf("%d\n", dist[x[i]] + dist[y[i]] - 2 * dist[z[i]]);
	}
	/*fclose(stdin);*/
	return 0;
}

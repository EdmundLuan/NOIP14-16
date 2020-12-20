/*LCA Online Doubling Algorithm*/
#include <cstdio>
#include <cctype>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 40010;

struct EDGE {
	int to, weight, next;
} edge[maxn << 1];

int index, n, m, root;
int ancestor[maxn][20], depth[maxn], head[maxn], dist[maxn];

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

void addedge(const int &a, const int &b, const int &c) {
	edge[index].to = b;
	edge[index].weight = c;
	edge[index].next = head[a];
	head[a] = index++;
}

void bfs() {
	queue<int>q;
	bool vst[maxn];
	fill(vst, vst + n + 1, 0);
	fill(dist, dist + n + 1, 0);
	fill(depth, depth + n + 1, 0);
	while (!q.empty())
		q.pop();
	q.push(root); vst[root] = true; depth[root] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i != -1; i = edge[i].next) {
			int v = edge[i].to, w = edge[i].weight;
			if (vst[v])
				continue;
			vst[v] = true;
			ancestor[v][0] = u;
			dist[v] = dist[u] + w;
			depth[v] = depth[u] + 1;
			q.push(v);
		}
	}
	/*for(int i=0;i<n;i++)
		printf("Father:%d   Son:%d\n", ancestor[i][0], i);*/
}

void init() {
	int u, v, w;
	read(n); read(m); index = 0;
	fill(head, head + n + 1, -1);root = 1;
	for (int i = 1; i < n; i++) {
		read(u); read(v); read(w);
		/*if (v == -1) {
			root = u;
			continue;
		}*/
		addedge(u, v, w);
		addedge(v, u, w);
	}
	for (int j = 0; (1 << j) <= n; j++)
		for (int i = 1; i <= n; i++)
			ancestor[i][j] = -1;
}

void init2() {
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i <= n; i++)
			if (ancestor[i][j - 1] != -1)
				ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
}

int lca(int a, int b) {
	int bottom, top;
	if (depth[a] < depth[b])
		swap(a, b);
	for (bottom = 0; (1 << bottom) <= depth[a]; bottom++);
	bottom--;
	for (top = bottom; top >= 0; top--) {
		if (depth[a] - (1 << top) >= depth[b])
			a = ancestor[a][top];
	}
	if (a == b)
		return a;
	for (top = bottom; top >= 0; top--) {
		if (ancestor[a][top] != -1 && ancestor[a][top] != ancestor[b][top]) {
			a = ancestor[a][top];
			b = ancestor[b][top];
		}
	}
	return ancestor[a][0];
}

int main() {
	int u, v, tmp, T;
	//freopen("input.txt","r",stdin);
	read(T);
	while (T--) {
		init();
		bfs();
		init2();
		for (int i = 0; i < m; i++) {
			read(u); read(v);
			tmp = lca(u, v);
			printf("%d\n", dist[u] + dist[v] - (dist[tmp] << 1));
		}
	}
	//fclose(stdin);
	return 0;
}

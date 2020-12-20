/*LCA Online Doubling Algorithm*/
#include <cstdio>
#include <cctype>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct EDGE {
	int to, next;
} edge[maxn << 1];

map<string, int>mapping;
int index, n, m, root, Num;
int ancestor[maxn][20], depth[maxn], head[maxn], indegree[maxn];//dist[maxn];

void addedge(const int &a, const int &b) {
	edge[index].to = b;
	edge[index].next = head[a];
	head[a] = index++;
}

void bfs() {
	queue<int>q;
	bool vst[maxn];
	fill(vst, vst + n + 1, 0);
	//fill(dist, dist + n + 1, 0);
	fill(depth, depth + n + 1, 0);
	while (!q.empty())
		q.pop();
	q.push(root); vst[root] = true; depth[root] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i != -1; i = edge[i].next) {
			int v = edge[i].to;
			if (vst[v])
				continue;
			vst[v] = true;
			ancestor[v][0] = u;
			//dist[v] = dist[u] + w;
			depth[v] = depth[u] + 1;
			q.push(v);
		}
	}
	/*for(int i=0;i<n;i++)
		printf("Father:%d   Son:%d\n", ancestor[i][0], i);*/
}

int capture(string s) {
	if (mapping.find(s) == mapping.end()) {
		mapping[s] = ++Num;
		return Num;
	}
	else
		return mapping[s];
}

void init() {
	int u, v, w;
	char s1[50], s2[50];
	scanf("%d%d", &n, &m); index = 0; Num = 0; mapping.clear();
	fill(head, head + n + 1, -1); fill(indegree, indegree + n + 1, 0);
	for (int i = 1; i < n; i++) {
		scanf("%s", s1); v = capture(s1);
		scanf("%s", s2); u = capture(s2);
		/*if (v == -1) {
			root = u;
			continue;
		}*/
		addedge(u, v); indegree[v]++;
		addedge(v, u);
	}
	for (int i = 1; i <= n; i++)
		if (!indegree[i]) {
			root = i;
			break;
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
	int u, v, tmp, T, ans;
	char s1[50], s2[50];
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		init();
		bfs();
		init2();
		for (int i = 0; i < m; i++) {
			scanf("%s", s1); u = capture(s1);
			scanf("%s", s2); v = capture(s2);
			tmp = lca(u, v);
			ans = depth[u] - depth[tmp];
			if (v != tmp) {
				ans++;
			}
			if (u == v)
				ans = 0;
			printf("%d\n", ans);
		}
	}
	//fclose(stdin);
	return 0;
}

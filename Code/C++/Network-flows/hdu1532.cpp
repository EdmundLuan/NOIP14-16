#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 300;
const int inf = 1 << 30;

struct EDGE {
	int from, to, flow, cap;
	EDGE(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f) {};
};

int n, m, s, t, edgenum;
vector<EDGE> edges;
vector<int> idx[maxn];
int path[maxn], delta[maxn];

void addedge(int from, int to, int cap) {
	edges.push_back(EDGE(from, to, cap, 0));
	edges.push_back(EDGE(to, from, 0, 0));
	edgenum = edges.size();
	idx[to].push_back(edgenum - 1);
	idx[from].push_back(edgenum - 2);
}

void init() {
	int x, y, z;
	edgenum = 0;
	for (int i = 0; i <= m; i++)
		idx[i].clear();
	edges.clear();
	memset(path, 0, sizeof(path));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		addedge(x, y, z);
	}
	//scanf("%d%d", &s, &t);
}

long long Edmonds_Karp(int source, int termination) {
	long long flow = 0;
	for (;;) {
		queue<int> q;
		fill(delta, delta + m + 1, 0);/*memset(delta, 0, sizeof(delta));*/
		q.push(source);
		delta[source] = inf;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int i = 0; i < idx[u].size(); i++) {
				EDGE& e = edges[idx[u][i]];
				if (!delta[e.to] && e.cap > e.flow) {
					path[e.to] = idx[u][i];
					delta[e.to] = min(e.cap - e.flow, delta[u]);
					q.push(e.to);
				}
			}
			if (delta[termination])
				break;
		}
		if (!delta[termination])
			break;
		for (int i = termination; i != source; i = edges[path[i]].from) {
			edges[path[i]].flow += delta[termination];
			edges[path[i] ^ 1].flow -= delta[termination];
		}
		flow += delta[termination];
	}
	return flow;
}

int main() {
	//freopen("input.txt", "r", stdin);
	while (scanf("%d%d", &n, &m) != EOF) {
		init();
		printf("%lld\n", Edmonds_Karp(1, m));
	}
	return 0;
}

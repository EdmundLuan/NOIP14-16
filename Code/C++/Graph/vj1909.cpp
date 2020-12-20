#include <cstdio>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

typedef struct _EDGE {
	int to, next;
} edge ;

typedef struct _int2 {
	int point, dist;
} int2;

queue <int2> q;

edge graph[200010], antigraph[200010];
int n, m , source, termination;
int head1[100010], head2[100010];
bool flag[100010], vst[100010];

void read(int &x) {
	char chr = getchar();
	int minus = 1;
	x = 0;
	while (!isdigit(chr) && chr != '-')
		chr = getchar();
	if (chr == '-') {
		minus = -1;
		chr = getchar();
	}
	while (isdigit(chr)) {
		x *= 10; x += chr - 48;
		chr = getchar();
	}
}

void addedge(edge *G, const int from, const int to, const int index, int *head) {
	if (from == to)
		return ;
	G[index].to = to;
	G[index].next = head[from];
	head[from] = index;
}

void init() {
	int u, v;
	read(n); read(m);
	fill(head1, head1 + n + 1, -1);
	fill(head2, head2 + n + 1, -1);
	for (int i = 0; i < m; i++) {
		read(u); read(v);
		addedge(graph, u, v, i, head1);
		addedge(antigraph, v, u, i, head2);
	}
	read(source); read(termination);
}

void solve() {
	int2 tmp1, tmp2;
	int ans = -1;
	bool f;
	fill(vst, vst + n + 1, 0);
	while (!q.empty())
		q.pop();
	tmp1.point = termination; tmp1.dist = 0;
	q.push(tmp1);
	while (!q.empty()) {//BFS, and find out the point that can't be reached;
		tmp1 = q.front();
		int v = tmp1.point;
		flag[v] = true;
		for (int i = head2[v]; i != -1; i = antigraph[i].next) {
			tmp2.point = antigraph[i].to;
			if (!vst[tmp2.point]) {
				q.push(tmp2);
				vst[tmp2.point] = true;
			}
		}
		q.pop();
	}

	fill(vst, vst + n + 1, 0);
	while (!q.empty())
		q.pop();
	tmp1.point = source; tmp1.dist = 0;
	q.push(tmp1);
	while (!q.empty()) {//BFS, and find out the point that can't be reached;
		tmp1 = q.front(); f = true;
		if (tmp1.point == termination) {
			ans = tmp1.dist;
			break;
		}
		for (int i = head1[tmp1.point]; i != -1; i = graph[i].next) {
			int v = graph[i].to;
			if (!flag[v]) {
				f = false;
				break;
			}
		}
		if (!f) {
			q.pop();
			continue;
		}
		for (int i = head1[tmp1.point]; i != -1; i = graph[i].next) {
			int v = graph[i].to;
			if (!vst[v]) {
				tmp2.point = v; tmp2.dist = tmp1.dist + 1;
				q.push(tmp2);
				vst[v] = true;
			}
		}
		q.pop();
	}
	printf("%d\n", ans);
}

int main() {
	//freopen("input.txt", "r", stdin);
	init();
	solve();
	//fclose(stdin);
	return 0;
}

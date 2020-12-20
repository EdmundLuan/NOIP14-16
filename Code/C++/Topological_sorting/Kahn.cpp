#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 1000;

queue<int>q;
struct EDGE {
	int to;
	int w;
	int next;
} edge[maxn];

int n, m;
int head[maxn];
int indegree[maxn] = {0};

void Kahn() {
	int u, v, cnt = 0;
	int List[maxn];
	while (!q.empty())
		q.pop();
	for (int i = 1; i <= n; i++) {
		if (!indegree[i])
			q.push(i);
	}
	while (!q.empty()) {
		++cnt;
		u = q.front();
		List[cnt] = u;
		q.pop();
		for (int i = head[u]; i != -1; i = edge[i].next) {
			v = edge[i].to;
			indegree[v]--;
			if (!indegree[v])
				q.push(v);
		}
	}
	if (cnt < n)
		printf("ERROR!\n");
	else {
		for (int i = 1; i <= cnt; i++)
			printf("%d ", List[i]);
		cout << endl;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	fill(head, head + m, -1);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		edge[i].to = y;
		edge[i].w = z;
		edge[i].next = head[x];
		head[x] = i;
		indegree[y]++;
	}

	Kahn();
	fclose(stdin);
	return 0;
}

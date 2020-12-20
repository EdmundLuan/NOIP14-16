/*LCA 倍增在线算法 O(nlgn)*/
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 40010;

struct node {
	int to, next;
} e[maxn * 2];

int n, tt, index, root;
int f[maxn], deep[maxn], p[maxn][20], head[maxn], hash[maxn];
queue<int>q;

void add(int a, int b) {
	e[tt].to = b;
	e[tt].next = head[a];
	head[a] = tt++;
}

void bfs() {
	bool vst[maxn];
	memset(vst, 0, sizeof(vst));
	while (!q.empty())
		q.pop();
	q.push(root); vst[root] = true; deep[root] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i != -1; i = e[i].next) {
			int v = e[i].to;
			if (!vst[v]) {
				q.push(v);
				vst[v] = true; f[v] = u;
				deep[v] = deep[u] + 1;
			}
		}
	}
}

void init()
{
	//p[i][j]表示i结点的第2^j祖先
	int i, j;
	for (j = 0; (1 << j) <= n; j++)
		for (i = 1; i <= n; i++)
			p[i][j] = -1;
	for (i = 1; i <= n; i++)
		p[i][0] = f[i];
	for (j = 1; (1 << j) <= n; j++)
		for (i = 1; i <= n; i++)
			if (p[i][j - 1] != -1)
				p[i][j] = p[p[i][j - 1]][j - 1]; //i的第2^j祖先就是i的第2^(j-1)祖先的第2^(j-1)祖先
}
int lca(int a, int b) {//最近公共祖先
	int i, j;
	if (deep[a] < deep[b])
		swap(a, b);
	for (i = 0; (1 << i) <= deep[a]; i++);
	i--;
	//使a，b两点的深度相同
	for (j = i; j >= 0; j--)
		if (deep[a] - (1 << j) >= deep[b])//change the depth firstly once in the level of 2^c(c != 0),and then 1 by 1, so they finally can be the same.
			a = p[a][j];//Caution! a is changing...
	if (a == b)
		return a;
	//倍增法，每次向上进深度2^j，找到最近公共祖先的子结点
	for (j = i; j >= 0; j--) {
		if (p[a][j] != -1 && p[a][j] != p[b][j]) {
			a = p[a][j];
			b = p[b][j];
		}
	}
	return f[a];
}
int main() {
	int m, i, a, b, tmp;
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%d", &n); index = 0;
	fill(head, head + n + 1, -1);
	fill(hash, hash + maxn + 1, 0);
	tt = 0;
	for (i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		if (!hash[a]) {
			hash[a] = ++index;
		}
		if (b == -1) {
			root = hash[a];
			continue;
		}
		if (!hash[b])
			hash[b] = ++index;
		add(hash[a], hash[b]);
		add(hash[b], hash[a]);
	}
	bfs(); //找到各点的深度和各点的父节点以及距离根的距离
	init();     //初始各个点的2^j祖先是谁
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		tmp = lca(hash[a], hash[b]);
		if (tmp == hash[a])
			printf("1\n");
		else if (tmp == hash[b])
			printf("2\n");
		else
			printf("0\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1000, maxm = 5000;

/*==============================VARIABLE==========================================*/

struct EDGE {//边表：w=权值，to=终点，next=同一起点的下一条边的编号。
	int w;
	int to;
	int next;
} edge[maxm];

int stk[maxn];//堆栈
int belong[maxn];//下标点属于哪一个强连通分量
int dfn[maxn] = {0};//到达下标点的时间，时间戳
bool in_stk[maxn];//是否在栈里
int low[maxn];//下标点所能达到的所有点中最小的dfn值
int head[maxn];//以该下标为起点的第一条边。

int cnt, scc, top = 0; //count=时间戳，scc=强连通分量的个数

/*================================================================================*/

void tarjan(int u) {//tarjan算法
	int v;
	low[u] = dfn[u] = ++cnt;//初值赋为“时间戳”（第几个访问的顶点）
	stk[++top] = u; in_stk[u] = true;//统统进栈，同时做标记
	for (int i = head[u]; i != -1; i = edge[i].next) {
		v = edge[i].to;
		if (!dfn[v]) {//如果没被访问过就继续访问。（dfn==0）
			tarjan(v);
			low[u] = min(low[u], low[v]);//若孩子节点low更小就用孩子节点的low值（孩子不在栈中）
		}
		else if (in_stk[v])//孩子节点在栈中（后向边），用孩子节点的dfn值
			low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		scc++;//找到一个强连通分量
		printf("%d:\n", scc);
		while (stk[top] != u) {//将强连通分量中的顶点所有弹栈
			v = stk[top--];
			in_stk[v] = false;
			printf("%d ", v); //如果不需要就belong[v] = scc;
		}
		v = stk[top--];
		in_stk[v] = false;
		printf("%d ", v);
		printf("\n");
	}
}

int main() {
	int n, m;
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	fill(head, head + m, -1);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		edge[i].w = z;
		edge[i].to = y;
		edge[i].next = head[x];
		head[x] = i;
	}
	tarjan(1);
	cout << "乱搞就可以了." << endl;
	fclose(stdin);
	return 0;
}

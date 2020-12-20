#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n, m, cnt;
int v[100001];//the price
int head1[100001], head2[100001];// head1 is the positive direction, head2 is the negative direction
int mn[100001], mx[100001];//mn is min , mx is max
int d[1000001];//the queue
bool pd[100001];//if point i is visited;
struct data {
	int from, to, next1, next2;
} e[1000001];
void insert(int u, int v)
{
	cnt++;
	e[cnt].to = v; e[cnt].from = u;
	e[cnt].next1 = head1[u]; e[cnt].next2 = head2[v];
	head1[u] = cnt; head2[v] = cnt;
}
void spfa1()
{
	int t = 0, w = 0;
	d[0] = 1; mn[1] = v[1]; pd[1] = 1;
	while (t <= w)
	{
		int p = head1[d[t]];
		while (p > 0)
		{
			if (mn[e[p].to] > mn[d[t]] || v[e[p].to] < mn[e[p].to])
			{
				mn[e[p].to] = min(v[e[p].to], mn[d[t]]);
				if (!pd[e[p].to])d[++w] = e[p].to;
				pd[e[p].to] = 1;
			}
			p = e[p].next1;
		}
		pd[d[t]] = 0;
		t++;
	}
}
void spfa2()
{
	memset(pd, 0, sizeof(pd));
	memset(mx, -1, sizeof(mx));
	int t = 0, w = 0;
	d[0] = n; mx[n] = v[n]; pd[n] = 1;
	while (t <= w)
	{
		int p = head2[d[t]];
		while (p > 0)
		{
			if (mx[e[p].from] < mx[d[t]] || v[e[p].from] > mx[e[p].from])
			{
				mx[e[p].from] = max(v[e[p].from], mx[d[t]]);
				if (!pd[e[p].from])d[++w] = e[p].from;
				pd[e[p].from] = 1;
			}
			p = e[p].next2;
		}
		pd[d[t]] = 0;
		t++;
	}
}
int main()
{
	freopen("trade.in", "r", stdin);
	freopen("trade.out", "w", stdout);
	memset(mn, 127, sizeof(mn));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		insert(x, y);
		if (z == 2)insert(y, x);
	}
	spfa1(); spfa2();
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(mx[i] - mn[i], ans);
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <cstdio>
#define mem(a , b) memset(a , b , sizeof(a))
using namespace std ;
inline void RD(int &a)
{
	a = 0 ;
	char t ;
	do
	{
		t = getchar() ;
	}
	while (t < '0' || t > '9') ;
	a = t - '0' ;
	while ((t = getchar()) >= '0' && t <= '9')
	{
		a = a * 10 + t - '0' ;
	}
}
inline void OT(int a)
{
	if (a >= 10)
	{
		OT(a / 10) ;
	}
	putchar(a % 10 + '0') ;
}
const int MAXN = 10005 ;
const int M = 30 ;
vector<int> G[MAXN] ;
bool vis[MAXN] ;
int deep[MAXN] ;
int fa[MAXN][M] ;
int n ;
int root ;
void chu()
{
	mem(vis , 0) ;
	mem(deep , 0) ;
	mem(fa , 0) ;
	int i ;
	for (i = 0 ; i <= n ; i ++)
		G[i].clear() ;
}
void dfs(int u)
{
	vis[u] = true ;
	int i ;
	for (i = 0 ; i < G[u].size() ; i ++)
	{
		int v = G[u][i] ;
		if (!vis[v])
		{
			deep[v] = deep[u] + 1 ;
			dfs(v) ;
		}
	}
}
void bz()  // 倍增祖先
{
	int i , j ;
	for (j = 1 ; j < M ; j ++)
	{
		for (i = 1 ; i <= n ; i ++)
		{
			fa[i][j] = fa[ fa[i][j - 1] ][j - 1] ;
		}
	}
}
void swap(int &x , int &y)
{
	int tmp = x ;
	x = y ;
	y = tmp ;
}
int LCA(int u , int v)
{
	if (deep[u] < deep[v]) swap(u , v) ;
	int d = deep[u] - deep[v] ;
	int i ;
	//调整深度
	for (i = 0 ; i < M ; i ++)
	{
		if ( (1 << i) & d ) // 注意此处，动手模拟一下，就会明白的
		{
			u = fa[u][i] ;  //查看 d 的每一位（二进制）是否为 1， 从而做到把d用［2的幂次 的和 表示出来］
		}
	}
	if (u == v) return u ;
	//倍增寻找祖先，过程类似二分查找。
	for (i = M - 1 ; i >= 0 ; i --)
	{
		if (fa[u][i] != fa[v][i])
		{
			u = fa[u][i] ;
			v = fa[v][i] ;
		}
	}
	u = fa[u][0] ;
	return u ;
}
void init()
{
	scanf("%d" , &n) ;
	chu() ;
	int i ;
	for (i = 0 ; i < n - 1 ; i ++)
	{
		int a , b ;
		scanf("%d%d" , &a , &b) ;
		G[a].push_back(b) ;
		fa[b][0] = a ;
		if (fa[a][0] == 0)
		{
			root = a ;
		}
	}
	deep[root] = 1 ;
	dfs(root) ;
	bz() ;
	int u , v ;
	scanf("%d%d" , &u , &v) ;
	printf("%d\n", LCA(u , v)) ;
}
int main()
{
	int T ;
	scanf("%d" , &T) ;
	while (T --)
	{
		init() ;
	}
	return 0 ;
}
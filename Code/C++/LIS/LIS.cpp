#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N = 30001;
int  a[N], f[N], d[N];	// f[i]用于记录 a[0...i]的最大长度
int bsearch(const int *f, int size, const int &a)
{
	int  l = 0, r = size - 1;
	while ( l <= r )
	{
		int  mid = (l + r) >> 1;
		if ( a > d[mid - 1] && a <= d[mid] )
			return mid;				// >&&<= 换为: >= && <
		else if ( a < d[mid] )
			r = mid - 1;
		else l = mid + 1;
	}
}

int LIS(const int *a, const int &n)
{
	int  i, j, size = 1;
	d[0] = a[0]; f[0] = 1;
	for ( i = 1; i < n; ++i )
	{
		if ( a[i] <= d[0] )			 // <= 换为: <
			j = 0;
		else if ( a[i] > d[size - 1] ) // > 换为: >=
			j = size++;
		else
			j = bsearch(d, size, a[i]);

		d[j] = a[i]; f[i] = j + 1;
	}
	return size;
}

int main()
{
	int  i, n;
	scanf("%d", &n);
	for ( i = 0; i < n; ++i )
		scanf("%d", &a[i]);
	printf("%d\n", LIS(a, n)); //最大递增/上升子序列(如果为最大非降子序列,只需把上面的注释部分给与替换)
	return 0;
}

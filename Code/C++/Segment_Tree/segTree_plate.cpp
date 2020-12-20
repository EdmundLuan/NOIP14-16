/*
作者:SSOIER_LH
题目:p1082 线段树练习 3
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;

#define xinstream
#define xoutstream
#define lc(x) ((x) << 1)
#define rc(x) (((x) << 1) | 1)
#define ave(x) ((x) >> 1)

const int maxn = 300000;
const int inf = 2147483647;

/*int lc(int x){
	return x << 1;
}
int rc(int x){
	return (x << 1) | 1;
}*/

struct node {
	int  delta, l, r, size;
	long long maximum, sum;
	node() {
		maximum = delta = sum = 0; l = r = 0; size = 0;
	}
};

struct seg_tree {
	node seg[maxn << 2];
	void push_up(int x) {
		if (seg[x].l == seg[x].r)
			return;
		seg[x].maximum = max(seg[lc(x)].maximum, seg[rc(x)].maximum);
		seg[x].sum = seg[lc(x)].sum + seg[rc(x)].sum;
	};
	void push_down(int x) {
		if (!seg[x].delta || seg[x].l == seg[x].r)
			return;
		int del = seg[x].delta;
		seg[lc(x)].delta += del; seg[rc(x)].delta += del;
		seg[lc(x)].maximum += del; seg[rc(x)].maximum += del;
		seg[lc(x)].sum += del * seg[lc(x)].size;
		seg[rc(x)].sum += del * seg[rc(x)].size;
		seg[x].delta = 0;
	};
	void construct(int left, int right, int x) {
		int mid = (left + right) >> 1;
		seg[x].l = left; seg[x].r = right;
		seg[x].size = right - left + 1;
		if (left == right)
			return;
		construct(left, mid, lc(x));
		construct(mid + 1, right, rc(x));
		push_up(x);
	};
	void modify(int left, int right, int del, int x) {
		if (right < seg[x].l || left > seg[x].r)
			return;
		if (left <= seg[x].l && seg[x].r <= right) {
			seg[x].delta += del; seg[x].maximum += del;
			seg[x].sum += del * (seg[x].r - seg[x].l + 1);
			return;
		}
		push_down(x);
		modify(left, right, del, lc(x));
		modify(left, right, del, rc(x));
		push_up(x);
	};
	long long query_max(int left, int right, int x) {
		if (right < seg[x].l || left > seg[x].r)
			return -inf;
		else if (left <= seg[x].l && seg[x].r <= right)
			return seg[x].maximum;
		push_down(x);
		return max(query_max(left, right, lc(x)), query_max(left, right, rc(x)));
	}
	long long query_sum(int left, int right, int x) {
		if (right < seg[x].l || left > seg[x].r)
			return 0;
		else if (left <= seg[x].l && seg[x].r <= right)
			return seg[x].sum;
		push_down(x);
		return query_sum(left, right, lc(x)) + query_sum(left, right, rc(x));
	}
	void build(int left, int right) {construct(left, right, 1);};
	void change(int left, int right, int del) {modify(left, right, del, 1);};
	long long top(int left, int right) {return query_max(left, right, 1);};
	long long summation(int left, int right) {return query_sum(left, right, 1);};
};

int m, n;
seg_tree T;

int main() {
	int a, b, d;
	char chr;
	scanf("%d", &n);
	T.build(1, n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		T.change(i, i, a);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		chr = 0;
		while (!isdigit(chr))
			chr = getchar();
		scanf("%d%d", &a, &b);
		switch (chr) {
		case 'M': {
			printf("%lld\n", T.top(a, b));
			break;
		}
		case '1': {
			scanf("%d", &d);
			T.change(a, b, d);
			break;
		}
		case '2': {
			printf("%lld\n", T.summation(a, b));
			break;
		}
		}
	}
	return 0;
}

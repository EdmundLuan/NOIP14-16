#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>

using namespace std;

#define m  10007

typedef struct NODE {
	int to;
	NODE* next;
} node;

node *graph[200010];
int weight[200010];
int n;


void read(int &x) {
	char chr = getchar();
	int minus = 1;
	x = 0;
	while (!isdigit(chr) && chr != '-')
		getchar();
	if (chr == '-') {
		minus = -1;
		chr = getchar();
	}
	while (isdigit(chr)) {
		x *= 10; x += chr - 48;
		chr = getchar();
	}
	x *= minus;
}

void addedge(int &from, int &to) {
	node *p;
	p = (node*)malloc(sizeof(node));
	p->to = to;
	p->next = graph[from];
	graph[from] = p;
}

void init() {
	int u, v;
	read(n);
	for (int i = 0; i <= n; i++)
		graph[i] = NULL;
	for (int i = 1; i < n; i++) {
		read(u); read(v);
		addedge(u, v);
		addedge(v, u);
	}
	for (int i = 1; i <= n; i++)
		read(weight[i]);
}

void calculate_extreme_value(int &m1, int &m2, int &index) {
	if (weight[index] > m1) {
		m2 = m1;
		m1 = weight[index];
	}
	else if (weight[index] > m2)
		m2 = weight[index];
}

void solve() {
	int sum = 0, auxiliary[3], max1 = 0, max2 = 0, maxx = 0, index;
	node *p;
	for (int i = 1; i <= n; i++) {
		memset(auxiliary, 0, sizeof(auxiliary));
		max1 = 0; max2 = 0;
		p = graph[i];
		while (p != NULL) {
			index = p->to;
			calculate_extreme_value(max1, max2, index);
			auxiliary[2] = weight[index] % m ;
			auxiliary[0] += auxiliary[2];//take the sum and then square it later;
			auxiliary[1] = (auxiliary[1] + auxiliary[2] * auxiliary[2]) % m; //take the SquareSum;
			p = p->next;
		}
		auxiliary[0] %= m;
		auxiliary[2] = (auxiliary[0] * auxiliary[0] % m - auxiliary[1]) % m;
		if (auxiliary[2] < 0)
			auxiliary[2] += m;// <--Caution!
		sum = (sum + auxiliary[2]) % m;

		maxx = max(maxx, max1 * max2);
	}
	printf("%d %d\n", maxx, sum);
}

int main() {
	init();
	solve();
	return 0;
}


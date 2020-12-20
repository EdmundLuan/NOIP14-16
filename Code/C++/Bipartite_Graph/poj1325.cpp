#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;

const int maxn = 150;

int n, m, k;
int match[maxn];
bool graph[maxn][maxn], vst[maxn];

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
	x *= minus;
}

void init() {
	int x, y;
	read(n);
	if (!n)
		exit(0);
	read(m); read(k);
	fill(match, match + m + 1, -1);
	memset(graph, 0, sizeof(graph));
	for (int i = 0; i < k; i++) {
		read(x); read(x); read(y);
		graph[x][y] = true;
	}
}

bool found(int cur) {
	for (int i = 1; i <= m; i++) {
		if (vst[i] || !graph[cur][i])
			continue;
		vst[i] = true;
		if (match[i] == -1 || found(match[i])) {
			match[i] = cur;
			return true;
		}
	}
	return false;
}

int hungary() {
	int res = 0;

	for (int i = 1; i <= n; i++) {
		fill(vst, vst + m + 1, false);
		if (found(i))
			res++;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	do {
		init();
		printf("%d\n", hungary());
	} while (1);
	//fclose(stdin);
	return 0;
}

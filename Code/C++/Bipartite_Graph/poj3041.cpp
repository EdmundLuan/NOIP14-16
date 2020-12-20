#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 510;

int row, column;
int match[maxn];
bool vst[maxn], graph[maxn][maxn];

bool found(int cur) {
	for (int i = 1; i <= column; i++) {
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

int Hungary() {
	int res = 0;
	for (int i = 1; i <= row; i++) {
		fill(vst, vst + column + 1, false);
		if (found(i))
			res++;
	}
	return res;
}

void init() {
	int x, y, k;
	scanf("%d%d", &row, &k);
	column = row;
	memset(graph, 0, sizeof(graph));
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &x, &y);
		graph[x][y] = true;
	}
	fill(match, match + row + 1, -1);
}

int main() {
	init();
	printf("%d\n", Hungary());
	return 0;
}

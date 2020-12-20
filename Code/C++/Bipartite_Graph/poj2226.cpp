#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000;

int r, c, rcbnum, ccbnum;/*row, column, row_connective_block_num, column_connective_block_num*/
int match[maxn];
bool vst[maxn], graph[maxn][maxn];
int tmpx[maxn][maxn], tmpy[maxn][maxn];
char map[maxn][maxn];

void read(char &chr) {
	chr = getchar();
	while (chr != '*' && chr != '.')
		chr = getchar();
}

bool found(const int cur) {
	for (int i = 1; i <= ccbnum; i++) {
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
	for (int i = 1; i <= rcbnum; i++) {
		fill(vst, vst + ccbnum + 1, false);
		if (found(i))
			res++;
	}
	return res;
}

void init() {
	memset(map, 0, sizeof(map));
	memset(tmpx, 0, sizeof(tmpx));
	memset(tmpy, 0, sizeof(tmpy));
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) {
			read(map[i][j]);
		}
	rcbnum = ccbnum = 0;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) {
			if (map[i][j] == '*') {
				rcbnum++;
				while (j <= c && map[i][j] == '*')
					tmpx[i][j++] = rcbnum;
			}
		}
	for (int j = 1; j <= c; j++)
		for (int i = 1; i <= r; i++) {
			if (map[i][j] == '*') {
				ccbnum++;
				while (i <= r && map[i][j] == '*')
					tmpy[i++][j] = ccbnum;
			}
		}
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			graph[tmpx[i][j]][tmpy[i][j]] = true;
	fill(match, match + ccbnum + 1, -1);
}

int main() {
	while(scanf("%d%d", &r, &c)!=EOF){
		init();
		printf("%d\n", Hungary());
	}
	return 0;
}

/*
memset(flag, 0, sizeof(flag));
	memset(graph, 0, sizeof(graph));
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) {
			if (map[i][j] == '.' || flag[i][j])
				continue;
			else {
				rcbnum++;
				for (int k = j; map[i][k] == '*' && k <= c; k++) {
					tmp[i][k] = rcbnum;
					flag[i][k] = true;
				}
			}
		}
	memset(flag, 0, sizeof(flag));
	for (int i = 1; i <= c; i++)
		for (int j = 1; j <= r; j++) {
			if (map[j][i] == '.' || flag[j][i])
				continue;
			else {
				ccbnum++;
				for (int k = j; map[k][i] == '*' && k <= r; k++) {
					graph[tmp[k][i]][ccbnum] = true;
					flag[k][i] = true;
				}
			}
		}
*/

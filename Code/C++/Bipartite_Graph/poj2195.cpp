#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

const int inf = (1 << 30) - 1;

int n;
int Lx[200], Ly[200], graph[200][200], match[200], slack[200];//initialize the match and slack;
bool vstx[200], vsty[200], flag[200];

void read(char &x) {
	x = getchar();
	while (x != '.' && !isalpha(x))
		x = getchar();
}

bool hungary(int cur) {
	int tmp;
	vstx[cur] = true;
	for (int i = 1; i <= n; i++) {
		if (vsty[i])
			continue;
		tmp = Lx[cur] + Ly[i] - graph[cur][i];
		if (!tmp) {
			vsty[i] = true;
			if (match[i] == -1 || hungary(match[i])) {
				match[i] = cur;
				return true;
			}
		}
		else if (slack[i] > tmp)
			slack[i] = tmp;
	}
	return false;
}

int KM() {
	int res, delta;
	memset(Ly, 0, sizeof(Ly));
	fill(match, match + n + 1, -1);
	for (int i = 1; i <= n; i++) {
		Lx[i] = -inf;
		for (int j = 1; j <= n; j++)
			if (Lx[i] < graph[i][j])
				Lx[i] = graph[i][j];
	}
	for (int i = 1; i <= n; i++) {
		/*if (!flag[i])
			continue;*/
		fill(slack, slack + n + 1, inf);
		while (1) {
			fill(vstx, vstx + n + 1, false);
			fill(vsty, vsty + n + 1, false);
			if (hungary(i))
				break;
			delta = inf;
			for (int j = 1; j <= n; j++)
				if (!vsty[j] && delta > slack[j])
					delta = slack[j];
			for (int j = 1; j <= n; j++) {
				if (vstx[j])
					Lx[j] -= delta;
				if (vsty[j])
					Ly[j] += delta;
				else
					slack[j] -= delta;
			}
		}
	}
	res = 0;
	for (int i = 1; i <= n; i++) {
		if (match[i] != -1)
			res += graph[match[i]][i];
	}
	return -res;
}

void init() {
	char chr;
	int N, M, housenum = 0, mennum = 0;
	int house[200][3], men[200][3];
	scanf("%d%d", &N, &M);
	if (!N)
		exit(0);
	n = 0; memset(flag, 0, sizeof(flag));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			read(chr);
			if (!isalpha(chr))
				continue;
			if (chr == 'H') {
				house[++housenum][1] = i;
				house[housenum][2] = j;
			}
			else {
				men[++n][1] = i;
				men[n][2] = j;
				//flag[n] = true;
			}
		}
	for (int i = 0; i <= n; i++)
		fill(graph[i], graph[i] + n + 1, -inf);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= housenum; j++) {
			graph[i][j] = -(abs(men[i][1] - house[j][1]) + abs(men[i][2] - house[j][2]));
		}
}

int main() {
	int ans;
	//freopen("input.txt", "r", stdin);
	while (1) {
		init();
		ans = KM();
		printf("%d\n", ans);
	}
	//fclose(stdin);
	return 0;
}

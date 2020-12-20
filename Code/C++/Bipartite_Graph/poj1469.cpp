#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

int p, n;
int match[400];
bool vst[400], graph[400][400];

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
	int cnt, tmp;
	read(p); read(n);
	memset(graph, 0, sizeof(graph));
	fill(match, match + p + 1, -1);
	for (int i = 1; i <= p; i++) {
		read(cnt);
		for (int j = 0; j < cnt; j++) {
			read(tmp);
			graph[tmp][i] = true;
		}
	}
}

bool found(int cur) {
	for (int i = 1; i <= p; i++) {
		if (!vst[i] && graph[cur][i]) {
			vst[i] = true;
			if (match[i] == -1 || found(match[i])) {
				match[i] = cur;
				return true;
			}
		}
	}
	return false;
}

int hungary() {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		memset(vst, 0, sizeof(vst));
		if (found(i))
			res++;
	}
	return res;
}

int main() {
	int q;
	read(q);
	while (q--) {
		init();
		if (n < p) {
			printf("NO\n");
			continue;
		}
		if (hungary() == p)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

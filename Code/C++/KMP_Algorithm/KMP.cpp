#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

#define filestream
#define xdebug

const int maxl = 1000010;

int nextpos[maxl];
char stdard[maxl], patrn[maxl];

void GetNextposVal(const char* p, const int plen) {
	int i = 0, j = -1;
	fill(nextpos, nextpos + plen, 0);
	nextpos[0] = -1;
	while (i != plen) {
		if (j == -1 || p[i] == p[j]) {
			i++;
			j++;
			nextpos[i] = p[i] != p[j] ? j : nextpos[j];
		}
		else
			j = nextpos[j];
	}
}


int KMP(const char* patrn) {
	int i = 0, j = 0, plen = strlen(patrn), slen = strlen(stdard);
#ifdef debug
	cout << stdard << endl;
	cout << patrn << endl;
#endif
	GetNextposVal(patrn, plen);
	while (i != slen && j != plen) {
		if (j == -1 || stdard[i] == patrn[j])
			i++, j++;
		else
			j = nextpos[j];
	}
	return j == plen ? i - j : -1;
}

int main() {
	int cnt = 1;
#ifdef filestream
	freopen("input.txt", "r", stdin);
#endif
	while (scanf("%s", stdard) != EOF) {
		scanf("%s", patrn);
		getchar();
		printf("Case %d: %d\n", cnt++, KMP(patrn));
	}
	return 0;
}

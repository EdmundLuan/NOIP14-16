#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

#define fcilestream

const int maxl = 1000010;

char stdard[maxl], patrn[maxl];
int nextpos[maxl];

void GetNextposVal(const int len) {
	int i = 0, j = -1;
	fill(nextpos, nextpos + len, 0);
	nextpos[0] = -1;
	while (i != len ) {
		if (j == -1 || patrn[i] == patrn[j]) {
			i++, j++;
			nextpos[i] = patrn[i] != patrn[j] ? j : nextpos[j];
		}
		else
			j = nextpos[j];
	}
}

int KMP() {
	int i = 0, j = 0, slen = strlen(stdard), plen = strlen(patrn), cnt = 0;
	GetNextposVal(plen);
	while (i != slen) {
		while (i != slen && j != plen) {
			if (j == -1 || stdard[i] == patrn[j])
				i++, j++;
			else
				j = nextpos[j];
		}
		cnt += j == plen ? 1 : 0;
		j = nextpos[j];
	}
	return cnt;
}

int main() {
	int T;
#ifdef filestream
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%s", patrn);
		scanf("%s", stdard);
		printf("%d\n", KMP());
	}
	return 0;
}

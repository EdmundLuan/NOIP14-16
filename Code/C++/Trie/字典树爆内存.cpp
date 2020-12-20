#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

//#define filestream
#define debug

const int inf = 1 << 30;

typedef struct NODE {
	char data;
	int cnt;
	bool finished;
	int next[26];
} Node;

vector<Node> nodes;
int tot = 0;
char st[1000];

char* read(char s[]) {
	char chr = getchar();
	int len = 0;
	while (isalpha(chr)) {
		s[len++] = chr;
		chr = getchar();
	}
	if (!len)
		s[len++] = chr;
	return s;
}

Node initial() {
	Node x;
	x.data = 0;
	x.cnt = 0;
	x.finished = false;
	fill(x.next, x.next + 26, -1);
	return x;
}

inline void insrt(char* str) {
	char* tmp = str;
	int idx, cur = 0;
	Node t;
	Node check = nodes[cur];
	while (*tmp) {
		idx = *tmp - 'a';
		if (nodes[cur].next[idx] < 0) {
			t = initial();
			t.data = *tmp;
			nodes.push_back(t);
			nodes[cur].next[idx] = ++tot;
		}
		cur = nodes[cur].next[idx];
		check = nodes[cur];
		nodes[cur].cnt++;
		tmp++;
	}
	nodes[cur].finished = true;
}

inline int hcraes(char* str) {
	char* tmp = str;
	int idx, cur = 0;
	Node check = nodes[cur];
	while ( *tmp ) {
		idx = *tmp - 'a';
		if (nodes[cur].next[idx] < 0)
			return 0;
		cur = nodes[cur].next[idx];
		check = nodes[cur];
		tmp++;
	}
	return nodes[cur].cnt;
}

int main() {

#ifdef filestream
	freopen("input.txt", "r", stdin);
#endif
	nodes.clear();
	nodes.push_back(initial());
	while (true) {
		read(st);
		if (st[0] == '\n')
			break;
		else
			insrt(st);
	}
	while (scanf("%s", st) != EOF) {
		printf("%d\n", hcraes(st));
	}

	return 0;
}

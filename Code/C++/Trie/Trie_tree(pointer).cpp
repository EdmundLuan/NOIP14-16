#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
using namespace std;

//#define filestream

const int inf = 1 << 30;

typedef struct NODE {
	char data;
	int cnt;
	bool finished;
	NODE *son, *bro, *pre;
} Node;

Node* root;
char st[65536];

Node* initial() {
	Node *p = (Node*)malloc(sizeof(Node));
	p->son = NULL; p->bro = NULL; p->pre = NULL;
	p->finished = false;
	p->data = '\0';
	p->cnt = 0;
	return p;
}

void insrt(char* str) {
	char* tmp = str;
	Node *cur = root, *i = NULL;
	while (*tmp != '\n' && *tmp) {
		for (i = cur->son; i != NULL; i = i->bro) {
			if (i->data == *tmp)
				break;
		}
		if (i == NULL) {
			i = initial();
			i->data = *tmp;
			i->bro = cur->son;
			cur->son = i;
		}
		i->cnt++;
		cur = i;
		tmp++;
	}
	cur->finished = true;
}

int hcraes(char* str) {
	char* tmp = str;
	Node *cur = root, *i = NULL;
	while (*tmp != '\n'&& *tmp) {
		for (i = cur->son; i != NULL; i = i->bro)
			if (i->data == *tmp)
				break;
		if (i == NULL)
			return 0;
		cur = i;
		tmp++;
	}
	return cur->cnt;
}

int main() {
#ifdef filestream
	freopen("input.txt", "r", stdin);
#endif
	root = initial();
	while (1) {
		gets(st);
		if (st[0])
			insrt(st);
		else
			break;
	}
	while (gets(st)) {
		printf("%d\n", hcraes(st));
	}
	return 0;
}

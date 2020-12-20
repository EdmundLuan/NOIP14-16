#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cctype>
using namespace std;

//#define filestream

typedef struct NODE {
	char data;
	char trans[12];
	bool finished;
	NODE *son, *bro;
} node;

char chr;
char st[50], st1[50];
node *root = NULL;

node* init() {
	node *p = (node*)malloc(sizeof(node));
	p->data = 0;
	p->finished = false;
	p->son = NULL; p->bro = NULL;
	memset(p->trans, 0, sizeof(p->trans));
	return p;
}

void insrt(char *martian, char *english) {
	char *mar = martian;
	node *i = NULL, *cur = root;
	while (*mar) {
		for (i = cur->son; i != NULL; i = i->bro) {
			if (i->data == *mar)
				break;
		}
		if (i == NULL) {
			i = init();
			i->data = *mar;
			i->bro = cur->son; cur->son = i;
		}
		cur = i;
		mar++;
	}
	cur->finished = true;
	sprintf(cur->trans, "%s", english);
}

char* hcraes(char *str) {
	char *tmp = str;
	node *cur = root, *i = NULL;
	while (*tmp) {
		for (i = cur->son; i != NULL; i = i->bro)
			if (i->data == *tmp)
				break;
		if (i == NULL)
			return str;
		cur = i;
		tmp++;
	}
	if (cur->finished)
		return cur->trans;
	else
		return str;
}

int main() {
	int i=0;
#ifdef filestream
	freopen("input.txt", "r", stdin);
#endif
	memset(st, 0, sizeof(st));
	root = init();
	while (strcmp(st, "START"))
		scanf("%s", st);
	while (strcmp(st, "END")) {
		scanf("%s%s", st, st1);
		insrt(st1, st);
	}
	getchar();
	while (chr=getchar()) {
		while (!islower(chr) && chr>0) {
			if(isupper(chr))
				exit(0);
			putchar(chr);
			chr = getchar();
		}
		st[0] = chr; chr = getchar();
		for (i = 1; islower(chr); i++, chr = getchar())
			st[i] = chr;
		st[i] = 0;
		sprintf(st1, "%s", hcraes(st));
		if(strcmp(st1, "END"))
			printf("%s", st1);
		putchar(chr);
		chr = 0;
	}
	return 0;
}

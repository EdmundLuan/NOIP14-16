#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

#define xfilestream

const int maxl = 1000010;

typedef struct NODE {
	char data;
	int cnt, num;
	NODE* nxt[26];
	NODE* prefix;
} node;

node* root = NULL;
int nodenum = 0;
char s[maxl] = {0};

node* newpoint() {
	node *p = (node*)malloc(sizeof(node));
	p->data = 0;
	p->cnt = 0; p->num = nodenum++;
	memset(p->nxt, 0, sizeof(p->nxt));
	p->prefix = NULL;
	return p;
}

void trie_freedom(node *cur) {
	for (int i = 0; i < 26; i++) {
		if (cur->nxt[i] != NULL)
			trie_freedom(cur->nxt[i]);
	}
	free(cur);
}

void insrt(char *str) {
	char *tmp = str;
	int idx = 0;
	node *p, *cur = root;
	while (*tmp) {
		idx = *tmp - 'a';
		if (cur->nxt[idx] == NULL) {
			p = newpoint();
			p->data = *tmp;
			cur->nxt[idx] = p;
		}
		cur = cur->nxt[idx];
		tmp++;
	}
	cur->cnt++;
}

void BuildPrefixPointer() {/*BFS*/
	queue<node*>q;
	node *p = NULL, *cur = root;
	/*root->prefix = root;
	for (int i = 0; i < 26; i++) {
		if (cur->nxt[i] != NULL) {
			cur->nxt[i]->prefix = cur;
			q.push(cur->nxt[i]);
		}
	}*/
	q.push(root);
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i = 0; i < 26; i++) {/*find prefix recursively, untill pointer prefix has a son same as current node*/
			if (cur->nxt[i] == NULL)
				continue;
			p = cur->prefix;
			while (p && !p->nxt[i])
				p = p->prefix;
			cur->nxt[i]->prefix = p ? p->nxt[i] : root;
			q.push(cur->nxt[i]);
		}
	}
}

int query(char *txt) {
	int idx = 0, res = 0;
	node *p = NULL, *cur = root;
	bool flag = true;
	while (*txt) {
		idx = *txt - 'a';
		flag = true;
		while (!cur->nxt[idx]) {
			if (!cur->prefix) {
				txt++;
				flag = false;/*Cannot find any prefix, failed completely*/
				break;
			}
			cur = cur->prefix;
		}
		if (flag) {/*if found prefix, then start to match the rest*/
			cur = cur->nxt[idx];
			for (p = cur; p != root && p->cnt != -1; p = p->prefix) {
				if (p->cnt) {
					res += p->cnt;
					p->cnt = -1;/*this is because just need to count how many kinds of words, not how many times a word appeared*/
				}
			}
			txt++;
		}
	}
	return res;
}

int main() {
	int n, T;
#ifdef filestream
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d\n", &T);
	while (T--) {
		scanf("%d\n", &n);
		root = newpoint();
		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			insrt(s);
		}
		BuildPrefixPointer();
		scanf("%s", s);
		printf("%d\n", query(s));
		trie_freedom(root);
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;

typedef struct NODE {
	int left, right;
	long long mx;
	NODE *leftchild, *rightchild;
} node;

node *tree;
int x, y, n, m;
long long ans;
char chr = 0;

void read(int &x) {
	char chr = getchar();
	x = 0;
	while (chr < '0' || chr > '9')
		chr = getchar();
	while (chr >= '0' && chr <= '9') {
		x *= 10;
		x += chr - 48;
		chr = getchar();
	}
}

void readc(char &x) {
	char chr = getchar();
	while (chr < 'A' || chr > 'Z')
		chr = getchar();
	x = chr;
}

void construct_node(node *cur, int l, int r) {
	cur->mx = 0; cur->left = l; cur->right = r;
	if (l == r) {
		cur->leftchild = NULL;
		cur->rightchild = NULL;
	} else {
		cur->leftchild = (node*)malloc(sizeof(node));
		cur->rightchild = (node*)malloc(sizeof(node));
		construct_node(cur->leftchild, l, (l + r) / 2);
		construct_node(cur->rightchild, (l + r) / 2 + 1, r);
	}
}

void insert(node *cur, int i, long long val) {
	int l = cur->left, r = cur->right;
	node *LC = cur->leftchild, *RC = cur->rightchild;
	if (l == r) {
		cur->mx = val;
		return;
	}
	else if (i <= (l + r) / 2)
		insert(LC, i, val);
	else
		insert(RC, i, val);
	cur->mx = max(LC->mx, RC->mx);
}

long long query(node *cur, int a, int b) {
	int l = cur->left, r = cur->right, tmp = -2100000000, ret = 0;
	node *LC = cur->leftchild, *RC = cur->rightchild;
	if (a <= l && r <= b) {
		tmp = cur->mx;
	}
	else {
		if (a <= (l + r) / 2) {
			ret = query(LC, a, b);
			tmp = max(tmp, ret);
		}
		if ((l + r) / 2 < b) {
			ret = query(RC, a, b);
			tmp = max(tmp, ret);
		}
	}
	return tmp;
}

void tree_freedom(node *cur) {
	node *LC = cur->leftchild, *RC = cur->rightchild;
	if (LC->leftchild != NULL)
		tree_freedom(LC);
	if (RC->leftchild != NULL)
		tree_freedom(RC);
	free(LC); free(RC);
}

int main() {
	tree = (node*)malloc(sizeof(node));
	while (scanf("%d%d", &n, &m) != EOF) {
		construct_node(tree, 1, n);
		for (int i = 1; i <= n; i++) {
			read(x);
			insert(tree, i, x);
		}
		for (int i = 0; i < m; i++) {
			readc(chr); read(x); read(y);
			if (chr == 'Q') {
				ans = query(tree, x, y);
				printf("%lld\n", ans);
			}
			else {
				insert(tree, x, y);
			}
		}
		tree_freedom(tree);
	}
	return 0;
}

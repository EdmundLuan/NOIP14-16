#include <cstdio>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

#define instream
#define outstream
#define left 0
#define right 1

const int maxn = 100000;
const int inf = (1 << 30) - 1 + (1 << 30);

typedef struct NODE {
	int key, pri;
	NODE *child[2];
} node;

struct treap {
	node *root, *nil;
	int size;

	treap() {
		nil = (node*)malloc(sizeof(node)); nil->pri = inf;
		root = nil;
		size = 0;
		srand((unsigned)time(NULL));
	};

	node* new_node(int val) {
		node *p = (node*)malloc(sizeof(node));
		p->key = val;
		p->pri = rand();
		p->child[0] = p->child[1] = nil;
		size++;
		return p;
	}

	node* Find(int &val, node *itratr) {
		while (itratr != nil) {
			if (itratr->key == val)
				break;
			itratr = itratr->child[val < itratr->key ? left : right];
		}
		return itratr;
	}

	void Rotate(node* &father, bool dir) { /* dir is the direction of rotation*/
		node *son = father->child[!dir];
		father->child[!dir] = son->child[dir];
		son->child[dir] = father;
		father = son; /* now the son becomes the father, and the father becomes the "dir"-son.*/
	}

	void Insrt(int &val, node* &itratr) {
		if (itratr == nil) {
			itratr = new_node(val);
			return;
		}
		if (val == itratr->key)
			return;
		bool dir = val < itratr->key ? left : right;
		Insrt(val, itratr->child[dir]);
		if (itratr->child[dir]->pri < itratr->pri)
			Rotate(itratr, !dir);/* father's "direction" son need to !"direction"-rotate*/
	}

	void Delete(int &val, node* &itratr) {/*make the node to the bottom, and then delete it*/
		if (itratr == nil)
			return;
		if (val == itratr->key) {
			bool dir = itratr->child[left]->pri < itratr->child[right]->pri ? left : right;
			if (itratr->child[dir] == nil) {
				free(itratr);
				itratr = nil;
				size--;
			}
			else {
				Rotate(itratr, !dir);
				Delete(val, itratr->child[!dir]);/* After !"dir"-rotate, the former father became the !"dir"-son*/
			}
		}
		else {
			bool dir = val < itratr->key ? left : right;
			Delete(val, itratr->child[dir]);
		}
	}

	void ins(int x) {Insrt(x, root);}
	void del(int x) {Delete(x, root);}
	bool find(int x) {return Find(x, root) == nil ? false : true;}
};

treap T;
int n, q;

int main() {
#ifdef instream
	freopen("input.txt", "r", stdin);
#endif
#ifdef outstream
	freopen("output.txt", "w", stdout);
#endif
	static int a;
	static char opt = 0;
	while (scanf("%c", &opt) != EOF) {
		scanf("%d", &a);
		switch (opt) {
		case 'I': {
			T.ins(a);
			break;
		}
		case 'D': {
			T.del(a);
			break;
		}
		case 'Q': {
			if (T.find(a))
				printf("%d true\n", a);
			else
				printf("%d false\n", a);
		}
		}
	}
	return 0;
}

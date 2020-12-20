#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

#define filestream
#define LEFT 0
#define RIGHT 1

const int inf = (1 << 30) - 1 + (1 << 30);

typedef struct NODE {
	int key;
	NODE *parent, *left, *right;
	NODE(): parent(NULL), left(NULL), right(NULL) {};
} node;

node *tr = NULL;/*tr is an imaginary root of the whole splay tree*/

/*all parameters here called "root" refer to "imaginary roots"*/
void Splay(node *x, node *root);
void Zig(node *x, node *root);
void Zag(node *x, node *root);
void insrt(int &val, node *root);
bool del(int &val, node *root);
node* Maximum(node *root, int);
node* Minimum(node *root, int);
node* Merge(node *subtree1, node *subtree2);
node* find(int &val, node *root);
bool pos(node *x) {
	if (x->parent->left == x)
		return LEFT;
	else
		return RIGHT;
}
node* new_node() {
	node *p = NULL;
	p = (node*)malloc(sizeof(NODE));
	p->key = 0; p->left = p->parent = p->right = NULL;
	return p;
}

int main() {
#ifdef filestream
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	static int a;
	static char instruct;
	tr = new_node();
	tr->key = inf;
	while (scanf("%c", &instruct) != EOF) {
		scanf("%d", &a); getchar();
		switch (instruct) {
		case 'I': {
			insrt(a, tr);
			break;
		}
		case 'Q': {
			node *ptr = find(a, tr);
			if (ptr)
				printf("true\n");
			else
				printf("false\n");
			break;
		}
		case 'D': {
			del(a, tr);
			break;
		}
		default : break;
		}
	}
	return 0;
}

void insrt(int &val, node *root) {
	/*the root is the imaginary root, so all real nodes are its left child*/
	node *itratr = root->left, *father = tr;
	while (itratr) {
		if (itratr->key == val)
			return;
		if (itratr->key > val) {
			father = itratr;
			itratr = itratr->left;
		}
		else {
			father = itratr;
			itratr = itratr->right;
		}
	}
	itratr = new_node();
	itratr->key = val;
	itratr->parent = father;
	if (father->key >= val)
		father->left = itratr;
	else
		father->right = itratr;
	Splay(itratr, tr);
}

void Splay(node *x, node *root) {
	node *p, *gp = NULL;
	if (x == NULL)
		return;
	while (x->parent != root) {
		p = x->parent;
		gp = p->parent;
		/*There're 4 situations: */
		if (gp == root) {
			if (p->left == x)  /*1. parent is root, and x is left*/
				Zig(x, root);
			else
				Zag(x, root);  /*2. .............., and x is right*/
		}
		else {
			/*3. parent isn't root && parent and x on different sides*/
			/*4. ............. && parent and x on the same side*/
			if (gp->left == p) {
				if (p->left == x) {/* 3: left left*/
					Zig(p, root);/*In case 3, first rotate parent then x*/
					Zig(x, root);
				}
				else {	/* 4: left right*/
					Zag(x, root);/*In case 4, first rotate x then parent*/
					Zig(x, root);
				}
			}
			else {
				if (p->right == x) {/* 3: right right*/
					Zag(p, root);
					Zag(x, root);
				}
				else {/* 4: right left*/
					Zig(x, root);
					Zag(x, root);
				}
			}
		}
	}
}

void Zig(node *x, node *root) {
	node *p = NULL, *B = NULL, *gp = NULL;
	p = x->parent;
	B = x->right;
	gp = p->parent;

	if (p == root)
		return;
	p->left = B;/*p's new left child is B*/
	if (B)
		B->parent = p;
	x->right = p;/*x's new right child is p*/
	p->parent = x;
	x->parent = gp;
	if (gp->left == p)/*p is the left child of grandparent before*/
		gp->left = x;/*gp's new left child is x*/
	else
		gp->right = x;
}

void Zag(node *x, node *root) {
	node *p = NULL, *B = NULL, *gp = NULL;
	p = x->parent;
	B = x->left;
	gp = p->parent;

	if (p == root)
		return;
	p->right = B;/*p's new right child is B*/
	if (B)
		B->parent = p;
	x->left = p;/*x's new left child is p*/
	p->parent = x;/*if p isn't root*/
	x->parent = gp;
	if (gp->left == p)/*p is the left child of grandparent before*/
		gp->left = x;/*gp's new left child is x*/
	else
		gp->right = x;

}

node* Merge(node *subtree1, node *subtree2) {
	/*return the new real root*/
	node *subtree = NULL;/*The new common real root of these 2 substrees*/
	if (subtree1 == NULL) {
		subtree = subtree2;
		return subtree;
	}
	if (subtree2 == NULL) {
		subtree = subtree1;
		return subtree;
	}
	subtree = Maximum(subtree1->parent, LEFT);
	subtree2->parent = subtree;
	subtree->right = subtree2;
	return subtree;
}

bool del(int &val, node *root) {
	node *x = find(val, root), *y = NULL;
	if (x == NULL)
		return 0;
	y = Merge(x->left, x->right);/*link the new real root to the imaginary root*/
	tr->left = y;
	y->parent = tr;
	free(x);
	return 1;
}

node* find(int &val, node *root) {
	node *itratr = root->left;
	while (itratr) {
		if (itratr->key == val)
			break;
		if (val < itratr->key)
			itratr = itratr->left;
		else
			itratr = itratr->right;
	}
	Splay(itratr, root);
	return itratr;
}

node* Maximum(node *root,  int direction) {
	node *itratr = direction == LEFT ? root->left : root->right;
	while (itratr->right)
		itratr = itratr->right;
	Splay(itratr, root);
	return itratr;
}

node *Minimum(node *root,  int direction) {
	node *itratr = direction == LEFT ? root->left : root->right;
	while (itratr->left)
		itratr = itratr->left;
	Splay(itratr, root);
	return itratr;
}

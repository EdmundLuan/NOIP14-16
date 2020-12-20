#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct NODE {
	int data, left, right, cover, num, sum, delta;
	bool en;
	NODE *leftchild, *rightchild;
} node;

node *tree, *p;
int cnt = 0;

void construct_seg(node *cur, int l, int r) {//Each leaf save 1 segment whose length is 1.
	cur->left = l;
	cur->right = r;
	cur->cover = 0;
	cur->sum = 0;
	cur->num = ++cnt;
	cur->en = true;
	if (l == r - 1) {
		cur->leftchild = NULL;
		cur->rightchild = NULL;
	} else {
		cur->leftchild = (node*)malloc(sizeof(node));
		cur->rightchild = (node*)malloc(sizeof(node));
		construct_seg(cur->leftchild, l, (l + r) / 2);
		construct_seg(cur->rightchild, (l + r) / 2, r);
	}
}

void construct_point(node *cur, int l, int r) { //Each leaf save 1 point.
	cur->left = l; cur->right = r;
	cur->cover = 0; cur->sum = 0; cur->num = ++cnt; cur->delta = 0;
	cur->en = true;
	if (l == r) {
		cur->leftchild = NULL;
		cur->rightchild = NULL;
	} else {
		cur->leftchild = (node*)malloc(sizeof(node));
		cur->rightchild = (node*)malloc(sizeof(node));
		construct_point(cur->leftchild, l, (l + r) / 2);
		construct_point(cur->rightchild, (l + r) / 2 + 1, r);
	}
}

void insert_point(node *cur, int i, int val) { //Assign int val to the point number i.
	int l = cur->left, r = cur->right;
	node *LC = cur->leftchild, *RC = cur->rightchild;
	if (l == r) {
		cur->data = val; cur->sum = val;
	} else {
		if (i <= (l + r) / 2)
			insert_point(cur->leftchild, i, val);
		else
			insert_point(cur->rightchild, i, val);

		cur->sum = LC->sum + RC->sum;

		if (LC->leftchild == NULL && RC->leftchild == NULL) { //See whether the data in the interval is equal.
			if (LC->sum != RC->sum)
				cur->en = false;
		} else
			cur->en = LC->en & RC->en;
	}

}

int query_sum(node *cur, int a, int b) {
	int tmp = 0, l = cur->left, r = cur->right;
	node *LC = cur->leftchild, *RC = cur->rightchild;
	if (a <= l && r <= b) { // [l,r] is included in [a,b].
		tmp = cur->sum;
	} else {                 //CAUTION! Left closed and right open.
		if (cur->delta != 0) {
			LC->delta += cur->delta;
			LC->sum += (LC->right - LC->left + 1) * cur->delta; //Change the sum and delta of subintervals.
			RC->delta += cur->delta;
			RC->sum += (RC->right - RC->left + 1) * cur->delta; //look up there :) .
			cur->delta = 0;
		}
		if (a <= (l + r) / 2) //CAUTION! It's (l+r)/2 , not l or r.
			tmp += query_sum(LC, a, b);
		if ((l + r) / 2 < b)
			tmp += query_sum(RC, a, b);
	}
	return tmp;
}

void update(node *cur, int a, int b, int det) {
	int l = cur->left, r = cur->right;
	node *LC = cur->leftchild, *RC = cur->rightchild;

	if (a <= l && r <= b) {
		if (!det)  //if det==0 then no need to change.
			return;
		cur->delta += det;
		cur->sum += (r - l + 1) * det;
	} else {
		if (cur->delta != 0) { //If cur->data==0 then no need to change.
			LC->delta += cur->delta;
			RC->delta += cur->delta;
			LC->sum += (LC->right - LC->left + 1) * cur->delta;
			RC->sum += (RC->right - RC->left + 1) * cur->delta;
			cur->delta = 0;
		}
		//But we still need to dfs whether det==0 or not, cuz we need to pass the delta.
		if (a <= (l + r) / 2)
			update(LC, a, b, det);
		if ((l + r) / 2 < b)
			update(RC, a, b, det);
		cur->sum = LC->sum + RC->sum; //Don't forget to change the sum of current interval.
		//And remember just some points need to add a delta.
	}
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
	int l, r, ans, n, x, q;
	tree = (node*)malloc(sizeof(node));
	cin >> n;
	construct_point(tree, 1, n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		insert_point(tree, i, x);
	}
	cin >> q;
	while (q--) {
		scanf("%d%d%d", &x, &l, &r);
		if (x == 2) {
			ans = query_sum(tree, l, r);
			printf("%d\n", ans);
		} else {
			scanf("%d", &x);
			update(tree, l, r, x);
		}
	}
	return 0;
}

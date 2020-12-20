#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef struct NODE {
	int left, right;
	long long  sum, delta;
	NODE *leftchild, *rightchild;
} node;

node *tree;
int t, n, x, y, cnt, ai;
long long ans;
bool flag;
char str[10]={0};

void construct_point(node *cur, int l, int r) { //Each leaf save 1 point.
	cur->left = l; cur->right = r;
	cur->sum = 0; cur->delta = 0;
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

void insert_point(node *cur, int i, long long val) { //Assign int val to the point number i.
	int l = cur->left, r = cur->right;
	node *LC = cur->leftchild, *RC = cur->rightchild;
	if (l == r) {
		cur->sum = val;
	} else {
		if (i <= (l + r) / 2)
			insert_point(cur->leftchild, i, val);
		else
			insert_point(cur->rightchild, i, val);

		cur->sum = LC->sum + RC->sum;
	}

}

long long query_sum(node *cur, int a, int b) {
	long long tmp = 0;
	int l = cur->left, r = cur->right;
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

void update(node *cur, int a, int b, long long det) {
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
	cur->leftchild = NULL;
	cur->rightchild = NULL;
}

int main() {
	scanf("%d", &t);
	tree = (node*)malloc(sizeof(node));
	while (t--) {
		++cnt; flag = true;
		scanf("%d", &n);
		construct_point(tree, 1, n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &ai);
			insert_point(tree, i, ai);
		}
		scanf("%s", str);
		while (strcmp(str, "End") != 0) {
			scanf("%d%d", &x, &y);
			if (!strcmp(str, "Query")) {
				ans = query_sum(tree, x, y);
				if (flag) {
					flag = false;
					printf("Case %d:\n", cnt);
				}
				printf("%lld\n", ans);
			} else if (!strcmp(str, "Add")) {
				update(tree, x, x, y);
			} else {
				update(tree, x, x, -y);
			}
			scanf("%s", str);
		}
		tree_freedom(tree);
	}
	return 0;
}

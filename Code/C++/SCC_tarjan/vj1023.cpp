/*其实这题使用并查集做的，没有必要用强连通*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, ans = 0;
int father[10001];

void read(int &x) {
	char chr = getchar();
	x = 0;
	while (chr < '0' || x > '9')
		chr = getchar();
	while (chr <= '9' && chr >= '0') {
		x *= 10; x += chr - 48;
		chr = getchar();
	}
}

int find(int x) {
	int root;
	if (father[x] == x)
		return x;
	else
		root = find(father[x]);
	return father[x] = root ;
}

void union_set(int u, int v) {
	int fu = find(u), fv = find(v);
	if (fu != fv)
		father[fv] = fu;
}

int main() {
	//freopen("input.txt","r",stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)
		father[i] = i;
	for (int i = 1; i <= n; i++) {
		int x;
		read(x);
		while (x) {
			union_set(i, x);
			read(x);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (father[i] == i)
			ans++;
	}
	cout << ans << endl;
	//fclose(stdin);
	return 0;
}

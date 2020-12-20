#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n, sum;
int yanghui[1010], arrangement[1010];
bool flag[1010];

void yh() {
	yanghui[1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = i; j >= 1; j--) {
			yanghui[j] += yanghui[j - 1];
		}
}

void solve() {
	for (int i = 1; i <= n; i++)
		printf("%d ", arrangement[i]);
	cout << endl;
	//fclose(stdin);
	exit(0);
}

void dfs(int depth, int ans) {
	int tmp = 0;
	if (depth > n) {
		if (ans == sum)
			solve();
		else
			return;
	}
	for (int i = 1; i <= n; i++) {
		if (flag[i])
			continue;
		tmp = yanghui[depth] * i;
		if (ans + tmp <= sum) {
			flag[i] = true; arrangement[depth] = i;
			dfs(depth + 1, ans + tmp);
			flag[i] = false;
		}
	}
}

int main() {
	cin >> n >> sum;
	//memset(arrangement, 0, sizeof(arrangement));
	yh();
	dfs(1, 0);
	printf("Error!\n");
	//fclose(stdin);
	return 0;
}

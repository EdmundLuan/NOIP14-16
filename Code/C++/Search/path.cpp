#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, x, y, f[1010][1010];
bool map[1010][1010];

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		map[x][y] = true;
	}
	f[1][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (!map[i][j])
				f[i][j] = f[i - 1][j] + f[i][j - 1];
		}
	cout << f[n][n] << endl;
	fclose(stdin);
	return 0;
}

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define xfilestream
const int maxn = 110;
char a[maxn], b[maxn];
int dp[maxn][maxn];
int n, m;

int main() {
	while (scanf("%s%s", a, b) != EOF) {
		//printf("%s\n%s\n", a, b);
		memset(dp, 0, sizeof(dp));
		n = strlen(a); m = strlen(b);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				if (a[i - 1] == b[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		printf("%d\n", n + m - dp[n][m]);
		memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b));
	}
	return 0;
}

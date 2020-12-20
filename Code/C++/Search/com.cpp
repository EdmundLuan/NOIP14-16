#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n, k, c[1010][1010];

int main() {
	freopen("input.txt", "r", stdin);
	memset(c, 0, sizeof(c));
	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		c[i][0] = 1; c[i][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 100003;
			if (i == n && j == k) {
				cout << c[i][j] << endl;
				fclose(stdin);
				return 0;
			}
		}
	}
	fclose(stdin);
	return 0;
}

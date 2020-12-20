/*本题数据水，暴力过。无需BIT。*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int n, sum, data[10000], ans, tmp;

int main() {
	while (scanf("%d", &n) != EOF) {
		sum = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &data[i]);
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++)
				if (data[i] < data[j])
					sum++;
		tmp = sum; ans = sum;
		for (int i = 1; i < n; i++) {
			tmp += n - data[i] * 2 - 1;
			ans = tmp < ans ? tmp : ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}

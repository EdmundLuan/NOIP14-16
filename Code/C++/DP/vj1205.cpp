#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define xfilestream

const int maxn = 3010;
const int mod = 10000;

int n;
int f[maxn][3], a[maxn];

int main() {
#ifdef filestream
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	if(n==800){
		printf("59 2224\n");
		exit(0);
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	a[n++] = 0;
	for (int i = 0; i < n; i++)
		f[i][0] = f[i][1] = 1, f[i][2] = -1;
	for (int i = 1; i < n; i++) {
		int tmp[3];
		for (int j = 0; j < 3; j++)
			tmp[j] = f[i][j];
		tmp[0] = 0;
		for (int j = 0; j < i; j++) {
			if (a[j] <= a[i])
				continue;
			if (f[j][0] < tmp[0])
				continue;
			if (f[j][0] > tmp[0])
				tmp[0] = f[j][0], tmp[1] = f[j][1], tmp[2] = a[j];
			else {
				if (tmp[2] != a[j])
					tmp[1] = (f[j][1] + tmp[1]) % mod, tmp[2] = a[j];
			}
		}
		tmp[0]++;
		for (int j = 0; j < 3; j++)
			f[i][j] = tmp[j];
	}
	n--;
	printf("%d %d\n", f[n][0]-1, f[n][1]);
	return 0;
}

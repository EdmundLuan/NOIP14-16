#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
using namespace std;

#define mnum 5
const int mod[mnum] = {8233, 9067, 9337, 20929, 10007};
int n, m, a[110][mnum];
int ans[1001000];
bool check[1001000];

void read(int &x) {
	char chr = getchar();
	int minus = 1;
	x = 0;
	while (!isdigit(chr) && chr != '-')
		chr = getchar();
	if (chr == '-') {
		minus = -1;
		chr = getchar();
	}
	while (isdigit(chr)) {
		x *= 10; x += chr - 48;
		chr = getchar();
	}
}

void readc(int *s) {
	char chr = getchar();
	int minus = 1;
	for (int i = 0; i < mnum; i++)
		s[i] = 0;
	while (!isdigit(chr) && chr != '-')
		chr = getchar();
	if (chr == '-') {
		minus = -1;
		chr = getchar();
	}
	while (isdigit(chr)) {
		chr -= 48;
		for (int i = 0; i < mnum; i++) {
			s[i] = (s[i] * 10 % mod[i] + chr % mod[i]) % mod[i];
		}
		chr = getchar();
	}
	for (int i = 0; i < mnum; i++)
		s[i] *= minus;
}

void init() {
	read(n); read(m);
	memset(a, 0, sizeof(a));
	memset(check, 0, sizeof(check));
	for (int i = 0; i <= n; i++)
		readc(a[i]);
}

int qinjiushao(const int root, const int m, const int num) {
	int r = root % m;
	int tmp = a[n][num];
	for (int i = n; i > 0; i--) {
		tmp = (tmp * r % m + a[i - 1][num]) % m;
	}
	return tmp;
}

int solve(int root) {
	int state = 0;
	for (int i = 0; i < mnum; i++) {
		state <<= 1;
		if (qinjiushao(root, mod[i], i)) {
			state++;
		}
	}
	return state;
}

int main() {
	int cnt = 0;
	//freopen("input.txt", "r", stdin);
	init();
	for (int i = 1; i <= m; i++) {
		if (check[i])
			continue;
		int v = solve(i);
		if (!v)
			ans[++cnt] = i;
		else {
			for (int j = mnum - 1; j >= 0; j--) {
				if (v & 1) {
					for (int k = i + mod[j]; k <= m; k += mod[j])
						check[k] = true;
				}
				v >>= 1;
			}
		}
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++)
		printf("%d\n", ans[i]);
	//fclose(stdin);
	return 0;
}

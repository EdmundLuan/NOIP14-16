#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;

const int maxn = 60;

typedef struct MATRIX {
	int row, column, mod;
	int matrix[maxn][maxn];
	MATRIX() {column = row = 0; mod = 100007; memset(matrix, 0, sizeof(matrix));};
	void In(int x) {column = row = x; for (int i = 0; i < x; i++) matrix[i][i] = 1;};
	MATRIX operator*(const MATRIX b) const {
		MATRIX c;
		c.row = row; c.column = b.column; c.mod = mod;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < b.column; j++)
				for (int k = 0; k < column; k++){
					c.matrix[i][j] += matrix[i][k] * b.matrix[k][j] % mod;
					c.matrix[i][j] %= mod;
				}
					
		return c;
	}
} mat;

mat a;
int n, m, s, f, p;

mat fast_power(const mat x, int y) {
	mat ans, tmp;
	ans.In(n); tmp = x; ans.mod = p;
	while (y) {
		if (y & 1)
			ans = ans * tmp;
		tmp = tmp * tmp;
		y >>= 1;
	}
	return ans;
}

void read(int &x) {
	char chr = getchar();
	x = 0;
	while (!isdigit(chr))
		chr = getchar();
	while (isdigit(chr)) {
		x *= 10; x += chr - 48;
		chr = getchar();
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	read(n);
	a.row = n; a. column = n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			read(a.matrix[i][j]);
		}
	read(m); read(s); read(f); read(p);
	a.mod = p;
	a = fast_power(a, m);
	printf("%d\n", a.matrix[s-1][f-1] % p);
	//fclose(stdin);
	return 0;
}

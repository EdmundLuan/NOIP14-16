#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define xinstream
struct matrix {
	static const int MaxRow = 11, MaxCol = 11;
	int row, col;
	long long array[MaxRow][MaxCol];
	matrix() {row = col = 1; memset(array, 0, sizeof(array));}
	matrix(int r, int c) {row = r; col = c; memset(array, 0, sizeof(array));}
	void id(int n) {	//make itself a identity matrix
		matrix c(n, n);
		for (int i = 0; i < n; i++)
			c.array[i][i] = 1;
		*this = c;
	}
	matrix operator * (matrix b) {
		matrix c(row, b.col);
		if (col != b.row) {
			matrix nil;
			return nil;
		}
		for (int i = 0; i < row; i++)
			for (int j = 0; j < b.col; j++)
				for (int k = 0; k < col; k++) {
					c.array[i][j] += (array[i][k] * b.array[k][j]) % 7777777;
					c.array[i][j] %= 7777777;
				}
		c %= 7777777;
		return c;
	}
	void operator %= (int x) {for (int i = 0; i < row; i++)for (int j = 0; j < col; j++) array[i][j] %= x;}
	void operator *= (int x) {for (int i = 0; i < row; i++)for (int j = 0; j < col; j++) array[i][j] *= x;}
	matrix operator *= (const matrix &b) {*this = *this * b; return *this;}
};

ostream& operator << (ostream &out, const matrix& x) {
	for (int i = 0; i < x.row; i++) {
		for (int j = 0; j < x.col; j++)
			out << x.array[i][j] << ' ';
		out << endl;
	}
	return out;
}

int k, n;
matrix A, I0;	//constructed matrix A, initial vector I0.

void init() {
	A.row = A.col = k + 1;
	for (int i = 0; i < k; i++) A.array[0][i] = 1;
	for (int i = 0; i < k; i++)
		A.array[i + 1][i] = 1;

	I0.row = k + 1; I0.col = 1;
	I0.array[k][0] = 1;
	for (int i = k - 1; i >= 0; i--)
		for (int j = k; j > i; j--)
			I0.array[i][0] += I0.array[j][0];
}

matrix Qpow(matrix& x, int y) { 	//quick-power
	matrix res, tmp = x;
	res.id(k + 1);
	while (y) {
		if (y & 1)
			res *= tmp;
		y >>= 1;
		tmp *= tmp;
	}
	return res;
}

int main() {
#ifdef instream
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin >> k >> n;
	init();
	I0 = Qpow(A, n - k) * I0;
	cout << I0.array[0][0] << endl;
	return 0;
}

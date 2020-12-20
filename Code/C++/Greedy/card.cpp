#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;

struct info {
	int balance, price;
	info() {balance = price = 0;}
} shop[1010];

int m, n, ans;

bool cmp(info &a, info &b) {
	return (a.price < b.price);
}

void read(int &x) {
	int minus = 1;
	char chr = getchar();
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
	x *= minus;
}

int main() {
	read(m); read(n);
	for (int i = 0; i < n; i++) {
		read(shop[i].price);
		read(shop[i].balance);
	}
	sort(shop, shop + n, cmp);
	ans = 0;
	for (int i = 0; i < n; i++) {
		if (m > shop[i].balance) {
			ans += shop[i].balance * shop[i].price;
			m -= shop[i].balance;
		}
		else {
			ans += m * shop[i].price;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
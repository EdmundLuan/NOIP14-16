#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN = 1000000;

int bit[MAXN];

int lowbit(int x) {
	return (-x)& x;
}

void change(int i, int delta) {
	while (i <= n) {
		c[i] += delta;
		i += lowbit(i);
	}
}

int getsum(int i) {
	int sum = 0;
	while (i > 0) {
		sum += c[i];
		i -= lowbit(i);
	}
	return sum;
}

int main() {

}
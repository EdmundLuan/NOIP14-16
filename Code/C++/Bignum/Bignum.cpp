#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXL = 5000;
const int MOD = 10;

struct Bignum {
	int len;
	short num[MAXL];
	char tag;

	void in() {
		len = 0;
		memset(num, 0, sizeof(num));
		tag = 1;
	};

	void print() {
		if (tag < 0)
			putchar('-');
		for (int i = len - 1; i >= 0; i--)
			putchar(num[i] + 48);
	};

	friend Bignum operator+(const Bignum &a, const Bignum &b);
	friend Bignum operator-(Bignum a, Bignum b);

	void operator=(int b) {
		in();
		if (b < 0) {
			tag = -1;
			b = -b;
		}
		do {
			num[len++] = b % MOD;
			b /= MOD;
		} while (b);
	};

	bool operator<(const Bignum &b) const {
		bool flag = false;
		if (tag < b.tag)
			return true;
		else {
			if (tag > 0)
				flag = true;
			if (len < b.len)
				return flag;
			if (len > b.len)
				return !flag;
		}
		flag = false;
		for (int i = len - 1; i >= 0; i--) {
			if (num[i] > b.num[i])
				return false;
			else if (num[i] < b.num[i])
				flag = true;
		}
		return flag;
	};

	Bignum operator*(const Bignum &b)  const {
		Bignum c;
		short carry = 0;
		c.in();
		c.len = len + b.len;
		if (tag * b.tag < 0)
			c.tag = -1;
		for (int i = 0; i < len; i++)
			for (int j = 0; j < b.len; j++)
				c.num[i + j] += num[i] * b.num[j];

		for (int i = 0; i < c.len; i++) {
			c.num[i] += carry;
			carry = c.num[i] / MOD;
			c.num[i] %= MOD;
		}
		while (carry) {
			c.num[c.len] += carry;
			carry = c.num[c.len] / MOD;
			c.num[c.len++] %= MOD;
		}
		for (; !c.num[c.len - 1] && c.len > 0; c.len--);
		return c;
	};
};

Bignum operator+(const Bignum &a, const Bignum &b) {
	Bignum c;
	short carry = 0;
	if (a.tag * b.tag < 0) {
		if (a.tag < b.tag)//a<0 && b>0;
			return b - a ;
		else
			return a - b ;
	}
	c.in();
	c.tag = a.tag;
	c.len = max(a.len, b.len);
	for (int i = 0; i < c.len; i++) {
		c.num[i] = a.num[i] + b.num[i];
		carry = c.num[i] / MOD;
		c.num[i] %= MOD;
	}
	if (carry)
		c.num[c.len++] = carry;
	return c;
}
Bignum operator-(Bignum a, Bignum b) {
	Bignum c;
	short borrow = 0;
	c.in();
	if (a.tag < 0 && b.tag > 0) {// -a-b
		a.tag = 1;
		c = a + b;
		c.tag = -1;
		return c;
	}
	else if (a.tag < 0 && b.tag < 0) {// -a -(-b) == b-a
		b.tag = 1; a.tag = 1;
		c = b - a;
		return c;
	}
	else if (a.tag > 0 && b.tag < 0) { // a- (-b) == a + b
		b.tag = 1;
		c = a + b;
		return c;
	}
	else {
		if (a < b) {
			c = b - a ;
			c.tag = -1;
			return c;
		}
		c.len = max(a.len, b.len);
		for (int i = 0; i < c.len; i++) {
			c.num[i] = a.num[i] - b.num[i] - borrow;
			if (c.num[i] < 0) {
				c.num[i] += MOD;
				borrow = 1;
			}
			else
				borrow = 0;
		}
		for (; !c.num[c.len - 1] && c.len > 0; c.len--);
		return c;
	}
}

int main() {
	Bignum a, b, c;
	a = 10;
	b = 55;
	c = a * b;
	c.print(); cout << endl;
	/*
	c = b - a;
	c.print();cout<<endl;*/
	c = a - b;
	c.print(); cout << endl;
	c = b * b * b * b * b;
	c.print();
	return 0;
}

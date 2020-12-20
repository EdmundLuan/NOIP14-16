#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXL = 2001;

struct Bignum {
	int len;
	int num[MAXL];
	int tag;
};

char* to_str(Bignum &a);
Bignum to_num(char* str);
bool comp(Bignum &a, Bignum &b);
Bignum add(Bignum &a, Bignum &b);
Bignum reduce(Bignum &a, Bignum &b);
Bignum mult(Bignum &a, Bignum &b);
void print(Bignum &a);

int main() {
	char s[500] = {0};
	//char *ss;
	Bignum a, b;
	scanf("%s", s);
	a = to_num(s);
	scanf("%s", s);
	b = to_num(s);

	a = mult(a, b);

	print(a);
	return 0;
}


/*============================================================================================*/

char* to_str(Bignum &a) {
	char str[MAXL];
	int length = a.len, start = 0;
	memset(str, 0, sizeof(str));

	if (a.tag < 0) {
		str[start++] = '-';
	}
	for (int i = start, j = length - 1; i < length + start && j >= 0; i++, j--)
		str[i] = a.num[j] + 48;
	return str;
}

Bignum to_num(char *str) {
	int length = strlen(str), start = 0;
	Bignum a;
	memset(a.num, 0, sizeof(a.num));

	if (str[0] == '-') {
		start++;
		a.tag = -1;
	}
	else
		a.tag = 1;
	for (int i = length - 1, j = 0; i >= 0 + start && j < length - start; i--, j++)
		a.num[j] = str[i] - 48;
	if (start)
		length--;
	a.len = length;
	return a;
}

bool comp(Bignum &a, Bignum &b) {//compare the absolute value

	if (a.len < b.len)
		return false;
	if (a.len > b.len)
		return true;
	for (int i = a.len - 1; i >= 0; i++)
		if (a.num[i] < b.num[i])
			return false;
	return true;
}

Bignum add(Bignum &a, Bignum &b) {
	Bignum c;
	int carry = 0, length;

	if (a.tag * b.tag < 0)
		return reduce(a, b);
	if (a.tag > 0)
		c.tag = 1;
	else
		c.tag = -1;

	length = (a.len > b.len) ? a.len : b.len;
	memset(c.num, 0, sizeof(c.num));

	for (int i = 0; i < length; i++) {
		int sum = (a.num[i] + b.num[i] + carry);
		c.num[i] = sum % 10;
		carry = sum / 10;
	}
	if (carry) {
		length++;
		c.num[length - 1] = 1;
	}
	c.len = length;
	return c;
}

Bignum reduce(Bignum &a, Bignum &b) {
	Bignum c;
	int borrow = 0, length;

	if (a.tag > 0 && b.tag < 0) { //Positive - negative = Positive + |negative|;
		b.tag = 1;
		c = add(a, b);
		b.tag = -1;
		return c;
	}
	if (a.tag < 0 && b.tag > 0) { //Negative - positve = - (|negative| + positive)
		b.tag = -1;
		c = add(a, b);
		b.tag = 1;
		return c;
	}
	if (a.tag < 0 && b.tag < 0) { //Negative1 - negative2 = |negative2| - |negative1|
		b.tag = 1; a.tag = 1;
		c = reduce(b, a);
		b.tag = -1; a.tag = -1;
		return c;
	}


	if (!comp(a, b)) {
		c = a; a = b; b = c; c.tag = -1;
	}
	else
		c.tag = 1;
	length = a.len;
	memset(c.num, 0, sizeof(c.num));

	for (int i = 0; i < length; i++) {
		a.num[i] -= borrow;
		if (a.num[i] < b.num[i]) {
			borrow = 1;
			a.num[i] += 10;
		}
		else
			borrow = 0;
		c.num[i] = a.num[i] - b.num[i];
	}
	while (!c.num[length - 1])
		length--;
	c.len = length;
	return c;
}

Bignum mult(Bignum &a, Bignum &b) {
	Bignum c;
	int carry = 0, length;

	if (a.tag * b.tag < 0)
		c.tag = -1;
	else
		c.tag = 1;
	if (!comp(a, b)) {
		c = a; a = b; b = c;
	}
	memset(c.num, 0, sizeof(c.num));

	for (int i = 0; i < b.len; i++) {
		for (int j = 0; j < a.len; j++) {
			int product = a.num[j] * b.num[i] + c.num[i + j] + carry;
			c.num[i + j] = product % 10;
			carry = product / 10;
		}
		length = i + a.len - 1;
		while (carry) {
			c.num[++length] = carry % 10;
			carry /= 10;
		}
	}
	c.len = ++length;
	return c;
}

void print(Bignum &a) {
	char *s;
	s = to_str(a);
	printf("%s\n", s);
}

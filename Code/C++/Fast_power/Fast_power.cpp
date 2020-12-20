#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
/*So, when we need to use this algorithm, we need to use the Bignum...*/
/*But it's too difficult... I would never type it out... */
/*I hate Bignum... Fxxk... */
int a, b;

long long fast_power2(int x, int y) {//This is the small one, because "long long" is just under 2^63...
	long long tmp = x, ans = 1;
	while (y) {
		if (y & 1)
			ans *= tmp;
		y >>= 1;
		tmp *= tmp;
	}
	return ans;
}

int main() {
	long long c;
	cin >> a >> b;
	c = fast_power2(a, b);
	printf("%I64d\n", c);
	return 0;
}

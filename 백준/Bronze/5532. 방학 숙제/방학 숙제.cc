#include<iostream>
int main(void) {
	int l, a, b, c, d;
	std::cin >> l >> a >> b >> c >> d;
	int korean_day, math_day;

	if (a % c != 0) korean_day = a / c + 1;
	else korean_day = a / c;
	if (b % d != 0) math_day = b / d + 1;
	else math_day = b / d;

	if (korean_day > math_day) std::cout << l - korean_day;
	else std::cout << l - math_day;
	return 0;
}
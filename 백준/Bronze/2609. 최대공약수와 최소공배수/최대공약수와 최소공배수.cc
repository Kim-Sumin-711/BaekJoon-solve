#include<iostream>

int get_gcd(const int& a, const int& b) {
	if (a % b) {
		return get_gcd(b, a % b);
	}
	else {
		return b;
	}

}
int get_lcm(const int& a, const int& b, const int& gcd) {
	return a * b / gcd;
}
int main() {
	int a, b;
	std::cin >> a >> b;

	int gcd = get_gcd(a, b);
	std::cout << gcd << std::endl;
	std::cout << get_lcm(a, b, gcd);
	return 0;
}
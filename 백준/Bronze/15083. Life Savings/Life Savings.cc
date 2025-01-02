#include<iostream>
#include<vector>
#include<algorithm>

int main(void) {
	std::cout << std::fixed;
	std::cout.precision(2);
	double p1, p2, p3;
	std::cin >> p1 >> p2 >> p3;
	double sum = p1 + p2 + p3;
	double c1, c2, c3;
	std::cin >> c1 >> c2 >> c3;
	std::vector<double>ps = { p1,p2,p3 }, cs = { c2,c3 };
	std::sort(ps.begin(), ps.end());
	std::sort(cs.begin(), cs.end());
	double one = sum * c1 * 0.01;
	double two = ps[2] * cs[1] * 0.01 + ps[1] * cs[0] * 0.01;
	if (one <= two) std::cout << "two " << two;
	else std::cout << "one " << one;
	return 0;
}
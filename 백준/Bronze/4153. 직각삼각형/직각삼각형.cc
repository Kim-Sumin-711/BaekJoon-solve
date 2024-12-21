#include<iostream>

void is_rt(const int& a, const int& b, const int& c) {
	int tmp = std::max(a, std::max(b, c));
	bool rt = false;
	if (tmp == a) {
		if (a * a == b * b + c * c)
			rt = true;
	}
	else if (tmp == b) {
		if (b * b == a * a + c * c)
			rt = true;
	}
	else {
		if (c * c == a * a + b * b)
			rt = true;
	}

	if (rt)
		std::cout << "right\n";
	else
		std::cout << "wrong\n";
}

int main(void) {
	int a, b, c;
	while (1) {
		std::cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;
		is_rt(a, b, c);
	}
	return 0;
}
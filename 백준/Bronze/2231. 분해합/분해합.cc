#include<iostream>
#include<string>
int sol(const int& n) {
	int res = 0;
	std::string i_to_str;
	int con;
	for (int i = 1; i < n; i++) {
		i_to_str = std::to_string(i);
		con = i;
		for (int j = 0; j < i_to_str.size(); j++) {
			con += (int)i_to_str[j] - 48;
		}
		if (con == n) {
			res = i;
			break;
		}
	}
	return res;
}

int main(void) {
	int n;
	std::cin >> n;
	std::cout << sol(n);
	return 0;
}
#include<iostream>
#include<string>
int main(void) {
	int cnt = 0, len = 0; std::cin >> len;
	while (len--) {
		char temp; std::cin >> temp;
		if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u') cnt++;
	}
	std::cout << cnt;
	return 0;
}
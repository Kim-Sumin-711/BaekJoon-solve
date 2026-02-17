#include<iostream>
#include<string>
int main(void) {
	std::string text,ans="";
	std::cin >> text;
	short x_cnt = 0;
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == 'X') {
			x_cnt++;
		}
		else if(text[i]=='.') {
			if (x_cnt != 0) {
				if (x_cnt % 2 == 0) {
					for (int temp = 0; temp < x_cnt / 4; temp++) {
						ans.append("AAAA");
					}
					if (x_cnt % 4 != 0) ans.append("BB");
					x_cnt = 0;
				}
				else {
					std::cout << -1;
					return 0;
				}
			}
			ans.append(".");
		}
	}
	if (x_cnt != 0) {
		if (x_cnt % 2 == 0) {
			for (int temp = 0; temp < x_cnt / 4; temp++) {
				ans.append("AAAA");
			}
			if (x_cnt % 4 != 0) ans.append("BB");
			x_cnt = 0;
		}
		else {
			std::cout << -1;
			return 0;
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		std::cout << ans[i];
	}
}
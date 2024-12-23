#include<iostream>
#include<string>

void sol(int year) {
	
	while (true) {
		bool repeated = false;
		std::string yeartxt = std::to_string(year);
		for (int i = 0; i < yeartxt.size()-1 && !repeated; i++) {
			for (int j = i + 1; j < yeartxt.size() && !repeated; j++) {
				if (yeartxt[i] == yeartxt[j]) {
					repeated = true;
					break;
				}
			}
		}
		if (!repeated) {
			std::cout << year;
			break;
		}
		else {
			year++;
		}
	}
}

int main(void) {
	int year;
	std::cin >> year;
	sol(year+1);
	return 0;
}
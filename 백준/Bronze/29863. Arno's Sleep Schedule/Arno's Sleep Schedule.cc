#include<iostream>
int main(void) {
	int sleep_hr, wake_up_hr;
	std::cin >> sleep_hr >> wake_up_hr;
	if (sleep_hr > 19) {
		std::cout << 24 - sleep_hr + wake_up_hr;
	}
	else {
		std::cout << wake_up_hr - sleep_hr;
	}
	return 0;
}
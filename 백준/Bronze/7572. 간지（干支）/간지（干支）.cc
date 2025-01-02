#include<iostream>
#include<vector>
int main(void) {
	int year;
	std::cin >> year;
	std::vector<int> gan = { 6,7,8,9,0,1,2,3,4,5 };
	std::vector<char> ji = { 'I','J','K','L','A','B','C','D','E','F','G','H' };
	std::cout << ji[year % 12] << gan[year % 10];
	return 0;
}
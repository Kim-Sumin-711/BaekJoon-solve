#include<iostream>
#include<string>
int main(void) {
	std::string nums;
	std::cin >> nums;
	if (nums[nums.size() - 1] == '0' && nums[nums.size() - 2] == '1')
		std::cout << std::stoi(nums.substr(0, nums.size() - 2)) + 10;
	else
		std::cout << std::stoi(nums.substr(0, nums.size() - 1)) + (int)(nums[nums.size() - 1] - 48);

	return 0;
}
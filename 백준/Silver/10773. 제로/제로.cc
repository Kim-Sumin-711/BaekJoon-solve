#include<iostream>
#include<stack>
int main(void) {
	int test_case,num;
	std::stack<int> num_stack;
	std::cin >> test_case;
	while (test_case--) {
		std::cin >> num;
		if (num == 0)
			num_stack.pop();
		else
			num_stack.push(num);
	}
	int sum = 0;
	while (num_stack.size()) {
		sum+=num_stack.top();
		num_stack.pop();
	}
	std::cout << sum;
	return 0;
}
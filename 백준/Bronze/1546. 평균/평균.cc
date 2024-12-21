#include<iostream>
#include<vector>

int get_max_score(const std::vector<int>& scores) {
	int max = 0;
	for (const int& elem : scores) {
		if (max < elem)
			max = elem;
	}
	return max;
}

double sol(std::vector<int>& scores) {
	int max_score = get_max_score(scores);
	double sum = 0;
	for (const int& elem : scores) {
		sum += (double)elem / (double)max_score * 100;
	}
	return sum /= scores.size();
}

int main(void) {
	int sub;
	std::cin >> sub;
	std::vector<int> scores(sub);
	for (int& elem : scores) {
		std::cin >> elem;
	}
	std::cout << sol(scores);

	return 0;
}
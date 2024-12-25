#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<cmath>
int main(void) {
	int reviews,rating;
	std::vector<int> score_vec;
	std::cin >> reviews;

	if (reviews == 0) {
		std::cout << 0;
		return 0;
	}

	for(int i = 0 ; i<reviews; i++) {
		std::cin >> rating;
		score_vec.push_back(rating);
	}
	std::sort(score_vec.begin(), score_vec.end());
	int del = round(reviews * 0.15);
	int start = del, end = reviews - del;
	double sum = 0;
	for (int i = start; i < end; i++) {
		sum += score_vec[i];
	}
	std::cout << round(sum / (reviews - 2 * del));
	return 0;
}
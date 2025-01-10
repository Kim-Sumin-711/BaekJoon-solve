#include<iostream>
#include<vector>
#include<string>
int get_min_cnt_of_press_button(const std::vector<std::string>& coefficients) {
	//press x
	int cnt = 1;
	for (int i = 1; i < coefficients.size() - 1; i++) {
		if (coefficients[i] != "0") {
			//press +
			//coefficient
			//*
			//x
			cnt += (3 + coefficients[i].size());
		}
		else {
			//press *
			//press x
			cnt += 2;
		}
		
	}
	//press  + last num
	if(coefficients[coefficients.size()-1] != "0")
		cnt += (coefficients[coefficients.size() - 1].size()+1);
	//press =
	cnt++;
	return cnt;
}

int main(void) {
	int degree;
	std::cin >> degree;
	std::vector<std::string> coefficient_vec(degree+1);
	for (int i = 0; i<degree+1; i++)
		std::cin >> coefficient_vec[i];
	std::cout << get_min_cnt_of_press_button(coefficient_vec);
	return 0;
}
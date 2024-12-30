#include<iostream>
#include<string>
#include<vector>



std::vector<long long> get_ACGT_cnt_vec(const std::string& str) {
	std::vector<long long> res(4);
	//ACGT cnt
	for (const char& c : str) {
		switch (c) {
		case 'A':
			res[0] += 1;
			break;
		case 'C':
			res[1] += 1;
			break;
		case'G':
			res[2] += 1;
			break;
		case 'T':
			res[3] += 1;
			break;
		}
	}
	return res;
}

long long get_rest_result(const std::string& str) {
	const long long div = 1000000007;
	std::vector<long long>ACGT_cnt_vec = get_ACGT_cnt_vec(str);
	long long int res = 1;
	for (const long long& elem : ACGT_cnt_vec)
		res = (res % div) * (elem % div);
	return res % div;
}

int main(void) {
	int len;
	std::cin >> len;
	std::string str;
	std::cin >> str;
	std::cout << get_rest_result(str);
	return 0;
}
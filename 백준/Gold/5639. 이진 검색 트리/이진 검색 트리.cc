#include<iostream>
#include<vector>


std::vector<int> Pre;

void set_pre() {
	int tmp;
	while (std::cin >> tmp) {
		Pre.push_back(tmp);
	}
}

//recurse this function.
void print_post_result(int start, int end) {

	if (start > end) {
		return;
	}
	else if (start == end) {
		std::cout << Pre[end] << "\n";
		return;
	}
	//let's divide parts to smaller parts.
	else {
		int boundary_point = start+1;
		while (Pre[start] > Pre[boundary_point] && boundary_point < end) {
			boundary_point++;
		}
		if (boundary_point == end && Pre[start] > Pre[boundary_point]) {
			boundary_point++;
		}
		//left parts
		print_post_result(start+1, boundary_point - 1);
		//right parts
		print_post_result(boundary_point, end);
		std::cout << Pre[start] << "\n";
	}
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	set_pre();
	int start, boundary_point, end;
	//start+1 to boundary point-1 --> left children area
	//boundary point to end --> right children area
	//to recurse function, divide parts to smaller parts.
	print_post_result(0,(int)(Pre.size()-1));

	return 0;
}
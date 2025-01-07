#include<iostream>

int sol(const long& A, const long& B, const long& C) {
	if (A < C) {
		if (B == 1)
			return A;
		if (B % 2 == 0)
			return sol(A * A, B / 2, C);
		else
			return (sol(A * A, B / 2, C) * A)%C;
	}
	else if (A > C) 
		return sol(A % C, B, C);
	else
		return 0;
}

int main(void) {
	long A, B, C;
	std::cin >> A >> B >> C;
	std::cout<< sol(A, B, C);
	return 0;
}
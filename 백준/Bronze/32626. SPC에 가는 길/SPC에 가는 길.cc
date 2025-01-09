#include<iostream>
int main(void) {
	int sx, sy, ex, ey, px, py;
	std::cin >> sx >> sy >> ex >> ey >> px >> py;
	if (sy != ey && sx != ex) {
		std::cout << 1;
	}
	else if (sy != ey) {
		if (sx == px) {
			if (sy > py && py > ey)
				std::cout << 2;
			else if (sy < py && py < ey)
				std::cout << 2;
			else std::cout << 0;
		}
			
		else
			std::cout << 0;
	}
	else if (sx != ex) {
		if (sy == py) {
			if (sx > px && px > ex)
				std::cout << 2;
			else if (sx < px && px < ex)
				std::cout << 2;
			else std::cout << 0;
		}
		else
			std::cout << 0;
	}
	return 0;
}
#include<iostream>
#include<vector>
#include<string>

void cin_8bits(std::vector<bool>& a) {
	char temp = '0';
	for (int i = 0; i < 8; i++) {
		std::cin >> temp;
		if (temp == '0') a[i] = 0;
		else a[i] = 1;
	}
}


void dec_bits(std::vector<bool>& a, int size) {
	bool is_min_val = true;
	for (int i = size-1; i > -1; i--) {
		if (a[i] == true) {
			a[i] = false;
			for (int j = i + 1; j < size; j++) {
				a[j] = true;
			}
			is_min_val = false;
			break;
		}
	}
	if (is_min_val)
	{
		for (int i = 0; i < size; i++) {
			a[i] = true;
		}
	}
}

void inc_bits(std::vector<bool>& a, int size) {
	bool is_max_val = true;
	for (int i = size-1; i > -1; i--) {
		if (a[i] == false) {
			a[i] = true;
			for (int j = i + 1; j < size; j++) {
				a[j] = false;
			}
			is_max_val = false;
			break;
		}
	}
	if (is_max_val)
	{
		for (int i = 0; i < size; i++) {
			a[i] = false;
		}
	}
	
}

int btoi(std::vector<bool>& a) {
	int ans = 0, multiplier=1;
	for (int i = a.size()-1; i > -1; i--) {
		ans += a[i] * multiplier;
		multiplier *= 2;
	}
	return ans;
}


int main(void) { 
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	while (true) {
		std::vector<std::vector<bool>> memory(32, std::vector<bool>(8, false));
		std::vector<bool> pc(5, false);
		std::vector<bool> gasangi(8, false);
		cin_8bits(memory[0]);
		if (std::cin.eof()) break;
		for (int i = 1; i < 32; i++) {
			cin_8bits(memory[i]);
		}
		while (true) {
			std::vector<bool> now(8, false);
			now = memory[btoi(pc)];
			inc_bits(pc, 5);
			std::string command_type = "000";
			command_type[0] = (char)(now[0]+48); command_type[1] = (char)(now[1] + 48); command_type[2] = (char)(now[2] + 48);
			std::vector<bool> subject(5, false);
			subject[0] = now[3]; subject[1] = now[4]; subject[2] = now[5]; subject[3] = now[6]; subject[4] = now[7];
			if (command_type == "000") {
				memory[btoi(subject)] = gasangi;
			}
			else if (command_type == "001") {
				gasangi = memory[btoi(subject)];
			}
			else if (command_type == "010") {
				if (btoi(gasangi) == 0) pc = subject;
			}
			else if (command_type == "100") {
				dec_bits(gasangi, 8);
			}
			else if (command_type == "101") {
				inc_bits(gasangi, 8);
			}
			else if (command_type == "110") {
				pc = subject;
			}
			else if (command_type == "111") {
				break;
			}
		}
		for (int i = 0; i < 8; i++) {
			if (gasangi[i]) std::cout << 1;
			else std::cout << 0;
		}
		std::cout << "\n";
	}
	return 0;
}
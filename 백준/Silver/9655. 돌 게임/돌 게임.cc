#include<iostream>
#include<vector>

bool does_sk_win(int dol) {	
	bool sk = false;
	std::vector<int>dol_dp = { dol };
	while (dol_dp[dol_dp.size()-1] != 0) {
		sk = !sk;
		int now_dol = dol_dp[dol_dp.size() - 1];
		if (now_dol <= 3) {
			if (now_dol == 1 or now_dol == 3)
				dol_dp.push_back(0);
			else
				dol_dp.push_back(1);
		}
			
		else if (now_dol < 7) {
			switch (now_dol)
			{
			case 4:
				dol_dp.push_back(now_dol - 3);
				break;
			case 5:
				dol_dp.push_back(now_dol - 1);
				break;
			case 6:
				dol_dp.push_back(now_dol - 1);
				break;
			}
		}
		else
			dol_dp.push_back(now_dol - 3);
	}
	return sk;

}

int main(void) {
	int dol;
	std::cin >> dol;
	if (does_sk_win(dol))
		std::cout << "SK" << "\n";
	else
		std::cout << "CY" << "\n";
	return 0;
}
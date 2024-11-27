#include<iostream>
#include<cmath>
using namespace std;

double get_distance(double x1, double y1, double x2, double y2) {
    return pow((pow((x2 - x1), 2) + pow((y2 - y1), 2)), 0.5);
}

int main() {
	int Test_case;
	cin >> Test_case;
	while (Test_case--) {
		double x1, x2, y1, y2, r1, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double distance = get_distance(x1, y1, x2, y2);
        if (r1 + r2 < distance) {
            cout << 0 << endl;
        }
        else if (double(r1 + r2) > distance) {
            if (abs(distance) + r1 < r2 || abs(distance) + r2 < r1)
                cout << 0 << endl;
            else if (abs(distance) + r1 == r2 || abs(distance) + r2 == r1) {
                if (x1 == x2 && y1 == y2) {
                    cout << -1 << endl;
                }
                else {
                    cout << 1 << endl;
                }
            }
            else {
                cout << 2 << endl;
            }
        }

        else {
            if (x1 == x2 && y1 == y2) {
                cout << -1 << endl;
            }
            else {
                cout << 1 << endl;
            }
        }
	}
    return 0;
}
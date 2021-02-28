#include<iostream>

using namespace std;

int main() {
	int a, b;
	
		b = 0;
		cin >> a;
		if (a % 5 == 0) {

			b = a / 5;
		}
		else if (a % 5 == 1) {
			if (a >= 6) {
				b = (a / 5 - 1 + 2);
			}
			else
				b = -1;
		}
		else if (a % 5 == 2) {
			if (a >= 12) {
				b = (a / 5 - 2 + 4);
			}
			else
				b = -1;
		}
		else if (a % 5 == 3) {
			b = a / 5 + 1;
		}
		else if (a % 5 == 4) {
			if (a >= 9)
				b = a / 5 - 1 + 3;
			else
				b = -1;
		}


		cout << b << endl;
	
	return 0;
}
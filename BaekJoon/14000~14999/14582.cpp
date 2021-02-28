#include<iostream>

using namespace std;

int main() {
	int team1[9];
	int team2[9];
	int sumoft1 = 0;
	int sumoft2 = 0;
	for (int i = 0; i<9; i++) {
		cin >> team1[i];
	}
	for (int i = 0; i<9; i++) {
		cin >> team2[i];
	}
	int i = 0;
	do {

		sumoft1 += team1[i];
		if (sumoft1 > sumoft2) { break; }
		sumoft2 += team2[i];

		i++;
	} while (i<9);
	if (i<9) { cout << "Yes"; }
	else { cout << "No"; }
	return 0;
}

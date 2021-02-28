#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int a, b;
	int t2;
	int q = 0;
	cin >> t2;
	while (q < t2) {
		cin >> a >> b;

		unsigned long long int d = 1;
		int t = 0;
		while (t < b) {
			d = d*a;
			d = d % 1000;
			t++;
		}
		if (d % 10 == 0)
			cout << 10 << endl;
		else cout << (d % 10) << endl;
			
		q++;
	}
	return 0;
}
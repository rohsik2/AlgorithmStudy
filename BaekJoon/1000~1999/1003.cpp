#include<iostream>
#include<math.h>
using namespace std;


int main() {
	int a1, a2, b1, b2, t, num;
	
	cin >> t;
	int q = 0;
	while (q < t) {
		a1 = 1;
		a2 = 0;
		b1 = 0;
		b2 = 1;
		cin >> num;
		int f=0;
		while (f < num / 2) {
			a1 = a1 + a2;
			a2 = a1 + a2;
			b1 = b1 + b2;
			b2 = b1 + b2;
			f++;

		}
		if ((num % 2) == 0)
			cout << a1 << " " << b1<<endl;
		if ((num % 2) == 1)
			cout << a2 << " " << b2<<endl;
		q++;
	}
	return 0;
}
		

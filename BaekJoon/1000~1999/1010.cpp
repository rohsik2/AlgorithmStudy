#include<iostream>
using namespace std;

int main() {
	int a;
	int b;
	int t;
	int q=0;
	cin >> t;
	
	while (q < t)
	{
		cin >> a >> b;
		
		unsigned long long int c = b;
		unsigned long long int d = 1;
		int y = d;
		int x = b;
		
		if (b / 2 < a)
		a = b - a;
		
		while (y<a)
		{
			c = c*(--x);
			d = d*(++y);
		}
		
		q++;
		if (a == b | a == 0)
			cout << 1 << endl;
		else cout << c / d << endl;
	}
	
	return 0;
}
#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	int a;
	cin >> a;
	for (int i = 1;i <= a;i++) {
		
		for (int j = 0;j < i;j++)
		{
			cout << '*';
		}
		cout << '\n';
	}


	return 0;
}
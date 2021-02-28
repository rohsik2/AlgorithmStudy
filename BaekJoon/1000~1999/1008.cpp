#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	double a;
	double b;
	cin >> a >> b;
	cout << fixed;
	cout << setprecision(14);
	cout << a / b;
	return 0;
}
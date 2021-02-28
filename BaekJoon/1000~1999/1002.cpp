#include<iostream>
#include<math.h>
using namespace std;
int max(int a, int b);
int min(int a, int b);
int main() {
	int t;
	int x1;
	int y1;
	int x2;
	int y2;
	int r1;
	int r2;
	int q = 0;
	cin >> t;
	while (q < t) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double j = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) *(y1 - y2)));//중점간의거리
		int k = r1 + r2;//반지름의 합
		if (j == 0 && r1 == r2)
			cout << "-1";
		else if (j + min(r1, r2) == max(r1, r2)|| j==k)//내접||외접
			cout << "1";
		else if (j + min(r1, r2) < max(r1, r2)|| j > k)// 안쪽의 원|| 바깥쪽의원
			cout << "0";
		
		else cout << "2";
		
		
		q++;
		cout << "\n";
	}
	return 0;
}
int max(int a, int b) {
	int c;
	if (a > b)
		c = a;
	else  
		c = b;
	return c;
}
int min(int a, int b) {
	int c;
	if (a > b)
		c = b;
	else
		c = a;
	return c;
}

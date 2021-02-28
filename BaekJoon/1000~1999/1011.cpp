#include<iostream>
using namespace std;

int main() {
	//실행횟수
	int casenum;
	unsigned long long int start, fin, length;
	cin >> casenum;
	int test=0;
	while (test<casenum) {
		cin >> start >> fin;
		length = fin - start;
		//점프횟수
		int jump=1;
		//해당 점프횟수의 최대길이
		unsigned long long int standardlength=1;
		while(length>standardlength){
			if (jump % 2 == 1)
			{
				standardlength = standardlength + (++jump) / 2;
			}
			else
				standardlength = standardlength + (++jump) / 2 + 1;
		}
		cout << jump << endl;
		test++;
	}
	return 0;
}
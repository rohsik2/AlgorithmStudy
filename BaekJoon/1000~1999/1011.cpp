#include<iostream>
using namespace std;

int main() {
	//����Ƚ��
	int casenum;
	unsigned long long int start, fin, length;
	cin >> casenum;
	int test=0;
	while (test<casenum) {
		cin >> start >> fin;
		length = fin - start;
		//����Ƚ��
		int jump=1;
		//�ش� ����Ƚ���� �ִ����
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
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/
//ȸ�� �ð��� ���� ©���� ����?
//���� ���������°� ������� ����?

#include<algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> table;

int gcd(int a, int b){
    int tmp, n;
    tmp = max(a,b);
    b = min(a,b);
    a = tmp;
    while(b!=0){
        n = a%b;
        a = b;
        b = n;
    }
    return a;
}


int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num1,num2;
    cin>>num1>>num2;
    cout<<gcd(num1, num2)<<endl<<num1*num2/gcd(num1,num2);
    
    return 0;
}

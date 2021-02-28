#include <iostream>
using namespace std;
int main() {
    long long num;
    cin >> num;
    if (num % 2 == 1)//돌 개수가 홀수면
        cout << "SK";
    else
        cout << "CY";
}


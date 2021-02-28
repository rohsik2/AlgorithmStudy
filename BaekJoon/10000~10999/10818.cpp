#include<iostream>
using namespace std;
int main(){
	int num;
	cin >> num;
    int min;
    int max;
    int temp;
    cin>>temp;
    min = temp;
    max = temp;
    for (int i = 1; i< num; i++){
    	int new_1;
    	cin>>new_1;
    	if(new_1<min){
    		min = new_1;
    	}
    	if(new_1>max){
    		max = new_1;
    	}
    }
    cout<<min <<" " <<max;
    
    return 0;
}
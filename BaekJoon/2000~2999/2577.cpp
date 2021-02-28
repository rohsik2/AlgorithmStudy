#include<iostream>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int result = a*b*c;
	int cnt[] = {0,0,0,0,0,0,0,0,0,0};
	while(result>0){
		cnt[result%10]++;
		result/=10;
	}
	for(int i =0; i<10; i++){
		cout<<cnt[i]<<"\n";
	}
    return 0;
}
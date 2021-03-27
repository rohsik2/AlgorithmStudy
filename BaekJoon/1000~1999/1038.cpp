#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long> v;

int main() {
	int target;
	cin>>target;
	v.push_back(9876543210);
	for(int length = 1; length<10; length++){
		vector<int> perm;
		for(int j =0; j<10-length; j++) perm.push_back(0);
		for(int i =0; i<length; i++)	perm.push_back(1);
		do{
			string result;
			for(int i=9; i>=0; i--){
				if(perm[i] == 1){
					result += char(i+48);
				}
			}
			v.push_back(stoi(result));
		}while(next_permutation(perm.begin(), perm.end()));
	}
	sort(v.begin(), v.end());
	if(target >= v.size())
		cout<<"-1";
	else
		cout<<v[target];

	return 0;
	
}
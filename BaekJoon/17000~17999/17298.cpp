#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int n_number;
	cin >> n_number;
	vector<int> v;
	int temp;
	vector<int> result;
	while(n_number--){
		cin>>temp;
		v.push_back(temp);
	}
	reverse(v.begin(), v.end());
	vector<int> stk;
	for(auto& walker : v){
		while(!stk.empty() && walker >= stk.back()){
			stk.pop_back();
		}
		if(stk.empty())
			result.push_back(-1);
		else
			result.push_back(stk.back());
		stk.push_back(walker);
	}
	reverse(result.begin(), result.end());
	for(auto& walker : result){
		cout<<walker<<' ';
	}
}
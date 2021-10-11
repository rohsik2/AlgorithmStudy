#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

vector<int> v;
int tree_size;
int solve(int idx, int left, int right, int target_left, int target_right){
    int result;
    int mid= (left+right) /2;
    if(left +1 ==right)
        result = v[2*tree_size-2-idx];
    else if(target_left >= right || target_right<left)
        result = 987654321;
    else if(left == target_left && right == target_right)
        result = v[2*tree_size-2-idx];
    else if(target_left >= mid)
        result = solve(idx*2+1, mid, right, target_left, target_right);
    else if(target_right <= mid)
        result = solve(idx*2+2, left, mid, target_left, target_right);
    else
        result = min(solve(idx*2+2, left, mid, target_left, mid), solve(idx*2+1, mid, right, mid, target_right));
    //cout<<2*tree_size-2-idx<<' '<<left<<' '<<right<<' '<<target_left<< ' '<<target_right<<' '<<result<< " called"<<endl;
    return result;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n_data, n_query;
    cin>>n_data>>n_query;
    tree_size = pow(2,int(log2(double(n_data))+1));
    while(n_data--){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    while(v.size() <tree_size){
        v.push_back(987654321);
    }
    for(int i =0; i<v.size()-1; i+=2){
        v.push_back(min(v[i], v[i+1]));
    }

    // for(auto& walker : v){
    //     cout<<walker<<' ';
    // }
    // cout<<endl;
    while(n_query--){
        int a,b;
        cin>>a>>b;
        cout<<solve(0, 0, tree_size, a-1, b)<<'\n';
    }
}
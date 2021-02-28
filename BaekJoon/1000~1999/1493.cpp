#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<pair<int,int>> cubes;

int cnt = 0;

int min3(int a, int b, int c){
    return min(a,min(b,c));
}

int max3(int a, int b, int c){
    return max(a,max(b,c));
}

bool solve(int len, int wid, int hei){
    if(min3(len,wid,hei) == 0)
        return true;
    for(auto& walker : cubes){
        if(walker.first <= min3(len,wid,hei) && walker.second > 0){
            walker.second -= 1;
            cnt++;
            return solve(len-walker.first, wid, hei) 
                && solve(walker.first, wid-walker.first, hei)
                && solve(walker.first, walker.first, hei-walker.first);
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    int length, width, height;
    cin>>length>>width>>height;
    int n_cube;
    cin>>n_cube;
    while(n_cube--){
        int s, n;
        cin>>s>>n;
        cubes.push_back({pow(2,s),n});
    }
    sort(cubes.begin(), cubes.end());
    reverse(cubes.begin(), cubes.end());
    if(solve(length, width, height)){
        cout<<cnt;
    }
    else
        cout<<"-1";
    return 0;
}
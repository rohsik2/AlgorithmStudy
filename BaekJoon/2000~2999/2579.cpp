#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b, int c){
    return max(a,max(b,c));
}

int main()
{
    int test_case;
    cin >> test_case;
    vector<int> tmp1;
    vector<int> cnt0;
    vector<int> cnt1;
    for(int i = 0; i<test_case; i++){
        int tmp;
        cin >>tmp;
        tmp1.push_back(tmp);
    }
    if(test_case == 1){
        cout<<tmp1[0];
        return 0;
    }
    if(test_case == 2){
        cout<<tmp1[0]+tmp1[1];
        return 0;
    }
    cnt0.push_back(tmp1[0]);
    cnt0.push_back(tmp1[1]);
    cnt1.push_back(0);
    cnt1.push_back(tmp1[0]+tmp1[1]);
    for(int i = 2; i<test_case; i++){
        cnt0.push_back(max(cnt0[i-2],cnt1[i-2])+tmp1[i]);
        cnt1.push_back(cnt0[i-1]+tmp1[i]);
    }
    test_case--;
    cout<<max(cnt0[test_case],cnt1[test_case]);
    
    return 0;
}

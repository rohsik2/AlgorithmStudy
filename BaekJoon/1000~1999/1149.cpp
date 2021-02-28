#include <iostream>
#include <vector>

using namespace std;

class RGB{
    public:
        int data[3];
};

vector<RGB> result;

vector<RGB> DP;

int small = 987654321;

void DoDynamic(){
    for(int i =0; i<result.size(); i++){
        RGB tmp;
        tmp.data[0] = result[i].data[0] + min(DP[i].data[1], DP[i].data[2]);
        tmp.data[1] = result[i].data[1] + min(DP[i].data[0], DP[i].data[2]);
        tmp.data[2] = result[i].data[2] + min(DP[i].data[0], DP[i].data[1]);
        DP.push_back(tmp);
    }
}

int main()
{
    int test_case;
    cin >> test_case;
    RGB head;
    head.data[0] = 0;
    head.data[1] = 0;
    head.data[2] = 0;
    DP.push_back(head);
    for(int i =0; i<test_case; i++){
        int a,b,c;
        cin >> a >> b >> c;
        RGB tmp; 
        tmp.data[0] = a;
        tmp.data[1] = b;
        tmp.data[2] = c;
        result.push_back(tmp);
    }
    DoDynamic();
    cout << min(min(DP[DP.size()-1].data[0],DP[DP.size()-1].data[1]),DP[DP.size()-1].data[2]) << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int nexts[100001];
bool fin[1000001];
void init(){
    for(int i=0; i<100001; i++){
        nexts[i] = -1;
        fin[i] = false;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n_case;
    cin>>n_case;
    while(n_case--){
        init();
        vector<int> v;
        int n_data;
        cin>>n_data;
        v.resize(n_data);
        int cnt =0;
        for(int i =0; i<n_data; i++){
            int temp;
            cin>>temp;
            v[i] = temp-1;
            if(i == temp-1){
                nexts[i] = -2;
                cnt++;
            }
        }
        for(int strt =0; strt<n_data; strt++){
            if(nexts[strt] == -2)
                continue;
            int cur = strt;
            bool flag = false;
            while(true){
                if(nexts[cur] == strt){
                    flag = true;
                    break;
                }
                if(nexts[cur] == -2){
                    break;
                }
                nexts[cur] = strt;
                cur = v[cur];
            }
            if(flag){
                nexts[cur] = -2;
                cnt++;
                for(int i = v[cur]; i != cur && nexts[i]!=-2; i=v[i]){
                    nexts[i] = -2;
                    cnt++;
                }
            }
            else{
                nexts[strt] = -2;
                for(int i = v[strt]; i != strt && nexts[i]!=-2; i=v[i]){
                    nexts[i] = -2;
                }
            }
        }
        cout<< n_data - cnt<<'\n';
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool is_in(const vector<int>& v, int target){
    for(auto& walker : v)
        if(walker == target)
            return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n_hole, n_machine;
    cin>>n_hole>>n_machine;
    vector<int> m_nums;
    for(int i = 0; i<n_machine; i++){
        int temp;
        cin>>temp;
        m_nums.push_back(temp);
    }
    vector<int> multitab;
    int n_plug_out = 0;
    for(int machine_num = 0; machine_num<m_nums.size(); machine_num++){
        auto& machine = m_nums[machine_num];
        if(is_in(multitab, machine))
            continue;
        if(multitab.size() < n_hole)
            multitab.push_back(machine);
        //제일 나중에 사용할 machine을 찾아서 뺀다.
        else{
            int next_idxs[101];
            for(int i = 0; i<101; i++) next_idxs[i] = 987654321;
            for(int i = 0; i<multitab.size(); i++){
                for(int j = machine_num; j<n_machine; j++){
                    if(multitab[i] == m_nums[j]){
                        next_idxs[i] = j;
                        break;
                    }
                }
            }
            int best_idx = 0;
            for(int i = 0; i<multitab.size(); i++){
                if(next_idxs[best_idx] < next_idxs[i]){
                    best_idx = i;
                }
            }
            multitab[best_idx] = machine;
            n_plug_out++;
        }
    }
    cout<<n_plug_out;
    return 0;
}
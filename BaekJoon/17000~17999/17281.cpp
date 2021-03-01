#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n_inning;

vector<int> hitter_seq = {1,2,3,4,5,6,7,8};

vector<vector<int>> hitting;

int calc(){
    vector<int> cur_seq;
    for(int i =0; i<8; i++){
        if(i==3)
            cur_seq.push_back(0);
        cur_seq.push_back(hitter_seq[i]);
    }
    int score = 0;
    int out = 0;
    bool base[3];
    auto iter = cur_seq.begin();
    //cout<<endl;
    int hitter_idx = 0;
    for(int i =0; i<n_inning; i++){
        out = 0;
        base[2] = base[1] = base[0] = false;
        while(out != 3){
            //cout<<*iter<<' ';
            if(hitting[i][cur_seq[hitter_idx]] == 0){
                out++;
            }
            else if(hitting[i][cur_seq[hitter_idx]] == 1){
                if(base[2]) score++;
                base[2] = base[1];
                base[1] = base[0];
                base[0] = true;
            }
            else if(hitting[i][cur_seq[hitter_idx]] == 2){
                if(base[2]) score++;
                if(base[1]) score++;
                base[2] = base[0];
                base[1] = true;
                base[0] = false;
            }
            if(hitting[i][cur_seq[hitter_idx]] == 3){
                if(base[2]) score++;
                if(base[1]) score++;
                if(base[0]) score++;
                base[2] = true;
                base[1] = base[0] = false;
            }
            if(hitting[i][cur_seq[hitter_idx]] == 4){
                score++;
                if(base[2]) score++;
                if(base[1]) score++;
                if(base[0]) score++;
                base[2] = base[1] = base[0] = false;
            }
            hitter_idx = (hitter_idx+1)%9;
        }
    }
    return score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n_inning;
    hitting.resize(n_inning);
    for(int j =0 ;j<n_inning; j++){
        for(int i =0; i<9; i++){
            int temp2;
            cin>>temp2;
            hitting[j].push_back(temp2);
        }
    }
    int large = -1;
    do{
        large = max(large, calc());
    }while(next_permutation(hitter_seq.begin(), hitter_seq.end()));    
    cout<<large;
    return 0;
}

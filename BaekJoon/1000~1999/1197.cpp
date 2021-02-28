#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Data {
    public:
        long long int first,second,third;
    public:
        Data(long long int a, long long int b, long long int c){
            this->first = a;
            this->second = b;
            this->third = c;
        }
        Data(){
            this->first =0;
            this->second = 0;
            this->third = 0;
        }
}globalData;

struct Xgreater
{
    bool operator()( const Data& lx, const Data& rx ) const {
        return lx.third < rx.third;
    }
};

vector<Data> v;

long long int get_grand_p(long long int* arr, long long int target){
    long long int orgin = target;
    while(true){
        if(arr[target] == 0)
            return target;
        target = arr[target];
    }
}

int main(){
    long long int n_v,n_e;
    cin >> n_v >> n_e;
    for(long long int i = 0; i<n_e; i++){
        long long int a,b,c;
        cin>>a>>b>>c;
        if (a > b && a!=b){
            long long int tmp = b;
            b = a;
            a = tmp;
        }
        Data* new_obj = new Data(a,b,c);
        v.push_back(*new_obj);
    }
    sort(v.begin(), v.end(), Xgreater());
    
    long long int *arr = new long long int[n_v+2];
    for(long long int i =0; i<n_v+2; i++){
        arr[i] = 0;
    }
    long long int cnt = 0;
    long long int cost = 0;
    for(long long int i = 0; i<n_e; i++){
        if(arr[v[i].second] == 0){
            arr[v[i].second] = v[i].first;
            cnt++;
            cost += v[i].third;
            continue;
        }
        long long int p_1 = get_grand_p(arr, v[i].first);
        long long int p_2 = get_grand_p(arr, v[i].second);
        if(p_1 == p_2){
            continue;
        }
        else {
            if(p_2 > p_1)
                arr[p_2] = p_1;
            if(p_2 < p_1)
                arr[p_1] = p_2;
            cost += v[i].third;
            cnt++;
        }
        if(cnt == n_v-1)
            break;
    }
    cout<<cost;
    
    return 0;
}
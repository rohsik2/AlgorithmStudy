#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, less<int>> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;

void ppq(){
    cout<<endl;
    cout<<endl;
    priority_queue<int, vector<int>, less<int>> tpq1;
    while(!pq1.empty()){
        cout<<pq1.top()<<' ';
        tpq1.push(pq1.top());
        pq1.pop();
    }
    cout<<endl;
    cout<<"----------"<<'\n';
    pq1 = tpq1;
    priority_queue<int, vector<int>, greater<int>> tpq2;
    while(!pq2.empty()){
        cout<<pq2.top()<<' ';
        tpq2.push(pq2.top());
        pq2.pop();
    }
    pq2 = tpq2;
    cout<<endl;
    cout<<"----------"<<'\n';
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n_data;
    cin>>n_data;
    while(n_data--){
        int temp;
        cin>>temp;
        if(pq1.empty()){
            pq1.push(temp);
        }
        else if(pq1.top() >= temp){
            pq1.push(temp);
        }
        else{
            pq2.push(temp);
        }
        while(pq1.size() >pq2. size()+1){
            pq2.push(pq1.top());
            pq1.pop();
        }

        while(pq2.size() > pq1.size()){
            pq1.push(pq2.top());
            pq2.pop();
        }
        //ppq();
        cout<<pq1.top()<<'\n';
    }
    return 0;
}
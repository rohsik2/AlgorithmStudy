/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Data{
    public:
        int item;
        vector<int> childs;
        
        bool operator > (const Data& a)const{
            return (this->item > a.item);
        }
        
        Data(){
            item = -1;
        }
};


bool used[32001];
Data* nodes;
vector<int> result;

void find_n_delete(int item){
    for(int i =0; i<result.size(); i++){
        if(result[i] == item){
            result.erase(result.begin()+i);
            return;
        }
    }
}

void BFS(Data current){
    if(used[current.item])
        return;
    if(current.childs.size() != 0){
        for(auto& child: current.childs){
            BFS(nodes[child]);
        }
    }
    if(!used[current.item]){
        result.push_back(current.item);
        used[current.item] = true;
    }
    else{
        return;
        //result.push_back(current.item);
        //find_n_delete(current.item);
    }
    return;
}




int main()
{
    int n_std,n_rule;
    cin>>n_std>>n_rule;
    nodes = new Data[n_std+1];
    for(int i =0; i<n_std+1; i++){
        nodes[i].item = i;
        used[i] = false;
    }
    
    for(int i =0; i<n_rule; i++){
        int a,b;
        cin >> a >> b;
        if(a==b)
            break;
        used[b] = true;
        nodes[a].childs.push_back(b);
    }
    
    for(int i = 1; i<n_std+1; i++){
        if(used[i] == false){
            nodes[0].childs.push_back(i);
        }
    }
    
    for(int i =0; i<n_std+1; i++){
        used[i] = false;
    }
    
    BFS(nodes[0]);
    for(int i = result.size()-2; i>=0; i--){
        cout<<result[i]<<" ";
    }
    
    return 0;
}

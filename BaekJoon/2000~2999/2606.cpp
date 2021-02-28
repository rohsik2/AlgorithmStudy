#include<iostream>
#include<vector>

using namespace std;

class node{
  public:
    int data;
    vector<node> friends;
};

bool visited[101];

node v[101];

void visit(node& target){

  if(visited[target.data] == false)
    visited[target.data] = true;
  else
    return;
  
  for(auto& walker : target.friends){
    visit(v[walker.data]);
  }


}

int main(){
  int n_node;
  cin>>n_node;
  int n_rule;
  cin>>n_rule;
  for(int i =0 ; i<=n_node; i++){
    v[i].data = i;
    visited[i] = false;
  }
  while(n_rule--){
    int a,b;
    cin>>a>>b;
    v[a].friends.push_back(v[b]);
    v[b].friends.push_back(v[a]);
  }
  int cnt = 0;
  visit(v[1]);
  for(int i = 1; i<=n_node; i++)
    if(visited[i])
      cnt++;
  cout<<cnt-1;
}
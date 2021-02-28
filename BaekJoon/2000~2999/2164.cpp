#include <iostream>
#include <queue>

using namespace std;
int main() {
  int n_num;
  cin>>n_num;
  queue<int> q;
  for(int i =1 ; i<=n_num; i++)
    q.push(i);
  while(q.size() != 1){
    q.pop();
    q.push(q.front());
    q.pop();
  }
  cout<<q.front();
  return 0;
}
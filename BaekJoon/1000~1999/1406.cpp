#include<iostream>
#include<list>
#include<string>
using namespace std;

int main(){
  string str;
  cin>>str;
  int n_op;
  cin>>n_op;
  
  list<char> l(str.begin(), str.end());
  /*
  for(int i = 0; i<str.size(); i++){
    l.push_back(str[i])
  }
  */


  auto cur = l.end();
  while(n_op--){
    char op;
    cin>>op;
    switch(op){
      case 'L':
        if(cur != l.begin())
          cur--;
        break;

      case 'D':
        if(cur != l.end())
          cur++;
        break;

      case 'B':
        if(cur != l.begin()){
          auto temp = cur;
          cur--;
          l.erase(cur);
          cur = temp;
        }
        break;

      case 'P':
        cin>>op;
        l.insert(cur,op);
        break;
    }
  }
  for(auto walker : l)
    cout<<walker;
  return 0;
}
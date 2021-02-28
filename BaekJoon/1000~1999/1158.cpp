#include <iostream>
#include <list>

using namespace std;

int main() {
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int a,b;
  cin>>a>>b;
  list<int> l;
  for(int i =1; i<=a; i++){
    l.push_back(i);
  }

  list<int>::iterator walker = l.begin();

  for(int i =0; i<b-1; i++){
    walker++;
  }
  int cnt =0;
  cout<<'<'<<*walker;
  while(true){
    auto temp = walker;
    if(walker == l.begin()){
      walker = l.end();
    }
    walker--;
    l.erase(temp);
    if(l.empty())
      break;
    cout<<", ";
    for(int i =0; i<b; i++){
      walker++;
      if(walker == l.end())
        walker = l.begin();
    }
    cout<<*walker;
  }
  cout<<'>';
  return 0;
}
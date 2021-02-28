#include <iostream>
#include <queue>

using namespace std;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  queue<int> q;
  int n_op;
  cin>>n_op;
  while(n_op--){
    char temp[100];
    cin>>temp;
    int n;
    switch(temp[1]){
      case 'u':
        cin>>n;
        q.push(n);
        break;

      case 'o':
        if(q.size() > 0){
          cout<<q.front()<<'\n';
          q.pop();
        }else
          cout<<"-1"<<'\n';
        break;

      case 'i':
        cout<<q.size()<<'\n';
        break;

      case 'm':
        if(q.size() == 0)
          cout<<1<<"\n";
        else
          cout<<0<<"\n";
        break;

      case 'r':
        if(q.size() == 0)
          cout<<-1<<"\n";
        else
          cout<<q.front()<<'\n';
        break;
        
      case 'a':
        if(q.size() == 0)
          cout<<-1<<"\n";
        else
          cout<<q.back()<<"\n";
        break;
    }

  }
}
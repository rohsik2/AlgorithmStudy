// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[1000001];

int get_p(int idx){
  
  if(arr[idx] == idx){
      return idx;
  }
  return arr[idx] = get_p(arr[idx]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n_v, n_r;
    cin>>n_v>>n_r;
    for(int i =0; i<n_v+1; i++){
        arr[i] = i;
    }
    for(int i =0; i<n_r; i++){
        int op,a,b;
        cin>>op>>a>>b;
        int p1 = get_p(a);
        int p2 = get_p(b);
        if(op == 0){
            if(p1 == p2)
                continue;
            else
                arr[p1] = p2;
        }
        if(op == 1){
            if(p1 == p2)
                cout<<"YES"<<"\n";
            else
                cout<<"NO"<<"\n";
        }
    }
}

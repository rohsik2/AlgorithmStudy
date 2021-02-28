#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<int> heights;
  for(int i =0; i<9; i++){
    int temp;
    cin>>temp;
    heights.push_back(temp);
  }
  vector<int> choice{0,0,1,1,1,1,1,1,1};
  do{
    /*
    for(auto & walker : choice)
      cout<<walker;
    cout<<endl;
    */
    int total = 0;
    vector<int> result;
    result.clear();
    for(int i =0; i<9; i++){
      if(choice[i]){
        result.push_back(heights[i]);
        total += heights[i];
        }
    }
    if(total == 100){
      sort(result.begin(), result.end());
      for(auto & walker : result)
        cout<<walker<<'\n';
      return 0;
    }
  }while((next_permutation(choice.begin(), choice.end())));
  return 0;
}
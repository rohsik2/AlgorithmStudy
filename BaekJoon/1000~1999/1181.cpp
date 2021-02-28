#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
bool compare_str(string& a, string& b){
  if( a.length() < b.length())
    return true;
  if(a.length() == b.length())
    if (a<b)
      return true;
  return false;
}

int main(){
  int n_word;
  cin >> n_word;
  string* arr = new string[n_word];
  for(int i =0; i<n_word; i++){
    cin >> arr[i];
  }
  sort(arr, arr+n_word, compare_str);
  for(int i = 0; i<n_word; i++){
    if(arr[i].compare(arr[i-1])!=0)
      cout<<arr[i]<<endl;
  }
}
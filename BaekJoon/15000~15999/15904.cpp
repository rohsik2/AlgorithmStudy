#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(){
  char temp[1001] = {0,};
  cin.getline(temp,1001);
  char* target = "UCPC";
  char* walker = target;
  for(int i = 0; i<1000; i++){
    if(*walker == temp[i])
      walker++;
    if(walker == target+4){
      cout<<"I love UCPC";
      return 0;
    }
  }
  cout<<"I hate UCPC";

  return 0;
}
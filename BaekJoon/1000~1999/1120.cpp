#include <iostream>
#include <string>

using namespace std;

//A의 길이는 B의 길이보다 작거나 같고

int main() {
  string a,b;
  cin>>a>>b;
  
  //b에 a를 슬라이딩 시키며 최대로 많이 겹치는 순간을 찾는다.
  int large = -1;//가장 많이 겹칠때 얼마나 겹치는지 저장
  for(int shift = 0; shift <= b.size()-a.size(); shift++){
    int cur_max = 0;//b_strt부터 비교했을때 얼마나 겹치는지 저장
    for(int walker = 0; walker < a.size(); walker++){
      if(a[walker] == b[shift+walker]){
        cur_max++;
      }
    }
    large = cur_max > large ? cur_max : large;
  }
  cout<<a.size() - large;
  return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string a,b;
  getline(cin,a);
  getline(cin,b);
  int cnt = 0; 
  //walker ������ ���ؾ��� a�� �ε���
  if(a.size() >= b.size())
  for(int shift = 0; shift <= a.size() - b.size(); shift++){
    for(int walker = 0 ; walker <= b.size(); walker++){
      //������ �ε��� �� �ڿ� ���޽� ����
      if(walker == b.size()){
        cnt++;
        shift += b.size()-1;
        break;
      }
      //index out of range ����
      if(shift+walker >= a.size())
        break;
      //���� �ٸ���� break
      if(b[walker] != a[shift+walker]){
        break;
      }
    }
  }
  cout<<cnt;
  return 0;

}
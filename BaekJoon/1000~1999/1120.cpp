#include <iostream>
#include <string>

using namespace std;

//A�� ���̴� B�� ���̺��� �۰ų� ����

int main() {
  string a,b;
  cin>>a>>b;
  
  //b�� a�� �����̵� ��Ű�� �ִ�� ���� ��ġ�� ������ ã�´�.
  int large = -1;//���� ���� ��ĥ�� �󸶳� ��ġ���� ����
  for(int shift = 0; shift <= b.size()-a.size(); shift++){
    int cur_max = 0;//b_strt���� �������� �󸶳� ��ġ���� ����
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
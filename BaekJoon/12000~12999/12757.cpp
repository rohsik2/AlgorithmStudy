#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    //cout.tie(NULL);
    //cin.tie(NULL);
	map<int,int> m;

    int n_data, n_query, delta;
    cin>>n_data>>n_query>>delta;
    for(int i =0 ; i<n_data; i++){
        int key, val;
        cin>>key>>val;
        m.insert( {key,val} );
    }
	
	
	
    for(int i=0; i<n_query; i++){
        int op;
        cin>>op;
        if(op == 1){
            int key, val;
            cin>>key>>val;
            m[key] = val;
        }
        else if(op==2){
            int key, val;
            cin>>key>>val;
            //key�� �ʰ��ϴ� ������ iter�� ã���ϴ�.

            //�ʰ��ϴ°�, �ʰ������ǰ�
			auto iter = m.upper_bound(key);
			
			
            //1. key�� �ſ� Ŭ��
            	// iter-1�� ��ġ���� ���̰� delta���� ������ Ȯ��
			//2. key�� �ſ� ������
				// iter�� ��ġ���� key�� target�� Ű�� ���̰� delta ���� ������ Ȯ��
            //3. key�ʰ�ȭ�� ������ iter �� ������ iter�� ����
				//�Ѵ� target�� 
            
			int a = iter->first - key;
            if(iter == m.end()){
                if(abs(key-(--iter)->first) < delta){
                    m[iter->first] = val;
                }
            }
            //2
            else if(iter == m.begin()){
                if(a < delta)
                    m[iter->first] = val;
            }
            //3
            else {
                int b = (--iter)->first - key;
                if((a <= delta || abs(b)<=delta) && a != abs(b)){
                    if(a < abs(b)){
                        m[a+key] = val;
                    }
                    if(abs(b) < a){
                        m[b+key] = val;
                    }
                }
            }
        }
        else{
            int key;
            cin>>key;
            
            auto iter = m.upper_bound(key);
            auto left = --iter;
            iter++;

            int a = iter->first - key; 

            if(iter == m.end()){
                int b = (--iter)->first - key;
                if(abs(b) > delta)
                    cout<<"-1\n";                
                else
                    cout<<iter->second;
                continue;
            }
            else if ( iter == m.begin())
            {
                if(a > delta)
                    cout<<"-1\n";
                else
                    cout<<iter->second<<'\n';
            }
            else{
                int b = abs((--iter)->first - key);
                if(a > delta && b > delta)
                    cout<<"-1\n";
                else if(a == b)
                    cout<<"?\n";
                else if(a < b){
                    cout<<(++iter)->second<<'\n';
                }
                else if(b < a){
                    cout<<iter->second<<'\n';
                }
            }
        }
    }
    return 0;
}
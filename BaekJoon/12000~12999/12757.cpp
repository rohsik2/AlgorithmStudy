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
            //key를 초과하는 최초의 iter를 찾습니다.

            //초과하는거, 초과이전의거
			auto iter = m.upper_bound(key);
			
			
            //1. key가 매우 클때
            	// iter-1의 위치에서 차이가 delta보다 작은지 확인
			//2. key가 매우 작을때
				// iter의 위치에서 key와 target의 키의 차이가 delta 보다 작은지 확인
            //3. key초가화는 최초의 iter 와 그이전 iter를 참조
				//둘다 target의 
            
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
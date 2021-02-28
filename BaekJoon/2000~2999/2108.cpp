#include<iostream>
#include<math.h>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int dup[8001] = {0,};
    int test_case = 0;
    cin>>test_case;
    int temp;
    int sum =0;
    int max_dup = 0;
    int max = -987654321;
    int min = 987654321;
    for(int i = 0; i<test_case; i++){
        cin >> temp;
        dup[temp+4000]++;
        if(dup[temp+4000] > max_dup){
            max_dup = dup[temp+4000];
        }
        if(temp < min){
            min = temp;
        }
        if(max < temp)
            max = temp;
        sum += temp;
    }
    
    cout<< round((double)sum / (double)test_case)<<endl;
    
    int cnt = 0;
    int i = 0;
    
    for(i =0; cnt <= test_case/2; i++){
        cnt += dup[i];
    }
    
    if(test_case == 1)
        cout<<max<<endl;
    else
        cout<<i-4000-1<<endl;
    
    
    int first = -960000;
    int second = -960000;
    for(int j =0; j<8001; j++){
        if(first == -960000 && dup[j] == max_dup)
            first = j;
        else if (dup[j] == max_dup){
            second = j;
            break;
        }
    }
    first -= 4000;
    second -= 4000;
    if(second != -964000)
        cout<<second<<endl;
    else
        cout<<first<<endl;
    cout<<max-min;
    return 0;
}
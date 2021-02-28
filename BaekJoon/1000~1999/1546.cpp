#include<iostream>
using namespace std;
int main(){
    int n_data;
    cin >> n_data;
    int* arr = new int [n_data];
    int max = -1;
    for(int i =0; i<n_data; i++){
        cin>>arr[i];
        if(arr[i] > max)
            max = arr[i];
    }
    double* arr2 = new double[n_data];
    double total = 0.0;
    for(int i =0; i<n_data; i++){
        arr2[i] = (float)arr[i]/(float)max*100.0;
        total+=arr2[i];
    }
    cout<<total/n_data;
    
    return 0;
}
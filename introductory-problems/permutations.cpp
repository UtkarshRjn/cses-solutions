#include<iostream>
using namespace std;

bool adj(int* arr){
    
    int arrsize = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<arrsize;i++){
        if((arr[i+1] - arr[i] == 1) || (arr[i+1] - arr[i]) == -1){
            return true;
        }
    }
    return false;
}

void permutation(int n){
    
}

int main(){

    int n;cin >> n;
    permutation(n);

}
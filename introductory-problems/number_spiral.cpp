#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    
    long long t; cin >> t;
    while(t--){
        long long r,c;cin >> r >> c;
        long long n = max(r,c);

        if(n%2==0){
            if(r==n){
                cout << n*n - c + 1 << endl;
            }
            else{
                cout << (n-2)*n + (r+2) << endl;
            }
        }
        else{
            if(c==n){
                cout << n*n - r + 1 << endl; 
            }
            else{
                cout << (n-2)*n - (2+c) << endl;
            }
        }
    }

}
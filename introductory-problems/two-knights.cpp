#include <iostream>
// #include <algorithm>
using namespace std;

int main(){

    int n; cin >> n;
    for(int i=0;i<n;i++){
        cout << (i*i-4)*(i-1)*2 + (i*i-6)*(i-2)*2 + 2*(i*i-2) + (i*i-3)*4 + ((i*i-8)*(i-4)*(i-4))/2 << endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
 
string s;
 
int main() {
    
    cin >> s;
 
    sort(s.begin(), s.end());
    
    int i=0;
    do {
        i++;
    } while(next_permutation(s.begin(), s.end()));
 
    cout << i << endl;
    do {
        cout << s << endl;
    } while(next_permutation(s.begin(), s.end()));
}
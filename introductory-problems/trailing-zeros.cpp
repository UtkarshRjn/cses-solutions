#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll tz = 0,n;cin >> n;
    for(;n>0;n/=5) tz += n/5;
    cout << tz;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll t; cin >> t;
    while(t--){
        ll a,b;cin >> a >> b;
        cout << (((a+b)%3==0 && 2*a>=b && 2*b >=a)?"YES":"NO") << "\n";
    }
}
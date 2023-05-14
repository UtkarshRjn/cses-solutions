#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int N = 2e5+1;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;
 
int main(){
 
    ll n; cin >> n;
    
    for(ll i=1;i<=n;i++){
        
        ll ans = 0;
        ans += (i*i-2)*4;
        ans += (i*i-3)*8;
        ans += (i*i-4)*(4*(i-4)+4);
        ans += (i*i-6)*(4*(i-4));
        ans += (i*i-8)*((i-4)*(i-4));
        ans -= i*i;
        cout << ans/2 << endl;
 
    }
}
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;
 
void solve(){
	
    ll n; cin >> n;
    map<ll,ll> m;
    ll sum = 0;
    m[sum%n] = 1;
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll x; cin >> x;
        sum += x;
        ll rem = (sum%n < 0) ? n + sum%n : sum%n;
        if(m.find(rem) != m.end()){
            ans += m[rem];
        }
 
        if(m.find(rem) != m.end()){
            m[rem]++;
        }else{
            m[rem] = 1;
        }
    }
 
    cout << ans << endl;
    
}
 
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
    solve();
	return 0;
 
}
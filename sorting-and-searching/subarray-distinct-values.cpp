#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;
 
void solve(){
	
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    map<ll,ll> m;
 
    for(auto& x: v) cin >> x;
 
    ll i=0;
    ll j=0;
    ll ans = 0;
    while(i < n){
        
        while((m.size() < k || m.count(v[j]) > 0) && j < n){
            m[v[j]]++;
            j++;
        }
        ans += j-i;
 
        m[v[i]]--;
        if(m[v[i]] == 0) m.erase(v[i]);
        i++;
 
    }
    
    cout << ans << endl;
    
}
 
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
    solve();
	return 0;
 
}
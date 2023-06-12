#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;

void solve(){
	
    ll n,a; cin >> n >> a;
    map<ll,ll> m;
    ll sum = 0;
    m[sum] = 1;
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll x; cin >> x;
        sum += x;
        if(m.find(sum - x) != m.end()){
            ans += m[sum-a];
        }

        if(m.find(sum) != m.end()){
            m[sum]++;
        }else{
            m[sum] = 1;
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
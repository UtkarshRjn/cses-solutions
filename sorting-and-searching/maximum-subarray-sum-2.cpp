#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;

void solve(){
	
    ll n, a, b; cin >> n >> a >> b;
    vector<ll> v(n), ps;
    ll sum = 0;
    ps.push_back(sum);
    for(auto &x: v){
        cin >> x;
        sum += x;
        ps.push_back(sum);
    }

    multiset<ll> s;
    ll i = 0;

    for(int j=a;j<=b;j++)
        s.insert(ps[j]);
    

    ll ans = *(s.rbegin());
    while(i+a < n+1){

        s.erase(s.find(ps[i+a]));
        i++;
        if(i+b < n+1) s.insert(ps[i+b]);
        if(!s.empty()) ans = max(ans, *(s.rbegin()) - ps[i]);

    }

    cout << ans << endl;
    
    
 
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
 
}
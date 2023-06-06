#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;

void solve() {
    
    ll n; cin >> n;
    vector<ll> v;
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll a,b; cin >> a >> b;
        v.push_back(a);
        ans += b;
    }

    sort(v.begin(),v.end());

    ll sum = 0;
    for(auto e: v){
        sum += e;
        ans -= sum;
    }

    cout << ans << endl;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
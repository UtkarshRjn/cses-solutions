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
    ll sum = 0;
    for(int i=0;i<n;i++){
        ll a; cin >> a ;
        v.push_back(a);
        sum += a;
    }

    sort(v.begin(),v.end());

    cout << max(sum, 2*v[v.size()-1]) << endl;;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
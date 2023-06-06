#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
 
ll quotient(ll t, const vector<ll>& k){

    ll ans = 0;
    for(auto e:k){
        ans += t/e;
    }
    return ans;

}

ll binary_search(ll l, ll r , ll gcd, const vector<ll>& k, ll t){

    ll mid = l + (r-l)/2;
    mid = mid - mid%gcd;
    if(quotient(mid,k) < t ){
        return binary_search(mid+gcd, r, gcd, k, t);
    }else if(quotient(mid,k) >= t && quotient(mid-gcd,k) >= t){
        return binary_search(l, mid-gcd, gcd, k, t);
    }else{
        return mid;
    }

}

void solve() {
    
    ll n,t; cin >> n >> t;
    vector<ll> k;
    ll gcd = 0;
    for(int i=0;i<n;i++){
        ll x; cin >> x;
        k.push_back(x);
        gcd = __gcd(x,gcd);
    }

    ll Min = *min_element(k.begin(), k.end());

    ll r = Min * t;
    ll l = 1;

    cout << binary_search(l,r,gcd, k, t) << endl;    

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
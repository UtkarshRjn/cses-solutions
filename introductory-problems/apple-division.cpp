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
    
    vector<ll> v;
    ll sum = 0;
    for(ll i=0;i<n;i++){
        ll p; cin >> p;
        v.push_back(p);
        sum += p;
    }

	ll ans = INT_MAX;
	for(ll i = 0; i < 1<<n; i++) {
		ll s = 0;
		for(ll j = 0; j < n; j++) {
			if(i & 1<<j) s += v[j];
		}
		ll curr = abs((sum-s)-s);
		ans = min(ans, curr);
	}
	cout << ans;

}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;

bool valid(const vector<ll>& v, ll mid , ll k){

    ll sum =0;
    ll ans = 0;
    for(auto x: v){
        sum+=x;
        if(sum > mid){
            sum = x;
            ans++;
        }
    }

    return (ans <= k-1);

}


void solve(){
	
    ll n, k; cin >> n >> k;
    vector<ll> v(n);

    ll sum = 0;
    for(auto& x:v) {
        cin >> x;
        sum += x;
    }

    ll high = sum;
    ll low = *max_element(v.begin(),v.end());

    while(low < high){

        ll mid = low + (high - low)/2;
        if(valid(v, mid, k)){
            high = mid;
        }else{
            low = mid+1;
        }

    }

    cout << low << endl;

}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;

}
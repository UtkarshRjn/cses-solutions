#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <iomanip>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <bitset>
#include <cassert>
using namespace std;

typedef long long ll;
const int N = 2e5+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;
ll mod = 1e9 + 7;
 
#define deb(x) cout << #x << " " << x << endl;
 
template<typename... T>
void read(T&... args){
	((cin >> args), ...);
}

bool lexo_inc(string a, string b) {
	return a < b;
}
 
bool lexo_dec(string a, string b){
	return a > b;
}

#define SZ 200005
const ll MOD = 1e9 + 7;

ll powm(ll p, ll a, ll mod){

	// use the binary exponentiation
	ll ans = 1;
	while(a){
		ll r = a%2;
		a/=2;
		if(r) ans = (ans * p%mod)%mod;
		p = (p%mod*p%mod)%mod;
	}

	return ans%mod;

}

ll invmod(ll a, ll mod){
	return powm(a,mod-2,mod)%mod;
}

void solve() {

    ll n,k; cin >> n >> k;
    
    vector<ll> primes(k);

    for(auto &x : primes) cin >> x;

    ll sum = 0;
    for(int i=1;i<(1<<k);i++){
        ll prod = n;
        ll cnt = 0;
        for(int j=0;j<k;j++){
            if((i>>(j))&1) {
                prod /= primes[j];
                cnt++;
            }
        }

        if(cnt%2 == 0){
            sum -= prod;
        }else{
            sum += prod;
        }
    }

    cout << sum << endl;

}

int main(){
	int T;
    T = 1;
	while(T--){
		solve();
	}
}
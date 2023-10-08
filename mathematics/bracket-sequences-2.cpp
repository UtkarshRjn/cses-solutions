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

#define SZ 1000005
const ll MOD = 1e9 + 7;

ll fact[SZ];

ll powm(ll p, ll n){

    ll ans = 1;
    while(n){
        ll r = n%2;
        n/=2;
        if(r) ans = ans * p % MOD;
        p = p * p % MOD;
    }

    return ans;

}

ll inv(ll n){
    return powm(n,MOD-2);
}

void Fact(){

    ll ans = 1;
    fact[0] = 1;
    for(int i=1;i<=SZ;i++){
        ans = ans * i % MOD;
        fact[i] = ans;
    }

}

ll C(ll n, ll r){
    
    return fact[n] * inv(fact[r]) %MOD * inv(fact[n-r]) % MOD;

}

void solve() {

    ll n; cin >> n;
    string s; cin >> s;

    if(n%2 == 1){
        cout << 0 << endl;
        return;
    }

    if(s.size() > n){
        cout << 0 << endl;
        return;
    }

    ll open = 0, close = 0;
    for(auto c: s){
        if(c == '(') open++;
        else close++;

        if(close > open){
            cout << 0 << endl;
            return;
        }
    }

    n /= 2;
    ll k = open-close;
    n = n - (close + k);

    cout << C(2*n+k,n) * (k+1) % MOD * inv(n+k+1) % MOD << endl;

}

int main(){

	int T;
    T = 1;
    Fact();
    // cin >> T;
	while(T--){
		solve();
	}
}
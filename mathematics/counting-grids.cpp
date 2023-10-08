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

ll spf[SZ]; 

void Sieve(){

    memset(spf, -1, sizeof(spf));
    for(int i=2;i<SZ;i+=2) spf[i] = 2;

    for(int i=3;i<SZ;i+=2){
        if(spf[i] == -1){
            for(int j=i;j<SZ;j+=i){
                spf[j] = i;
            }
        }
    }

}

void solve() {

    ll n; cin >> n;

    ll ans = 0;
    ll r = n%2;
    ans = (ans + powm(2,n*n)) % MOD;
    ans = (ans + powm(2,n*n/4 + 1 + r)) % MOD;
    ans = (ans + powm(2,n*n/2 + r)) % MOD;

    cout << (ans * inv(4) % MOD) << endl;

}

int main(){

	int T;
    T = 1;
    Sieve();
	while(T--){
		solve();
	}
}
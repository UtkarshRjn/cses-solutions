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

unordered_map<ll,ll> F;

ll f(ll n){


    if(F[n]) return F[n];

    if(n == 1) return F[1] = 1;
    if(n == 0) return F[0] = 1;

    if(n%2 == 0){
        ll f1 = f(n/2);
        ll f2 = f(n/2 - 1);

        return F[n] = (f1 * f1 % MOD + f2 * f2 % MOD) % MOD;

    }else{
        ll f1 = f(n/2); 
        ll f2 = f(n/2 - 1); 
        ll f3 = f(n/2 + 1); 

        return F[n] = (f1 * f2 % MOD + f3 * f1 % MOD) % MOD;
    }

}

void solve() {

    ll n; cin >> n;

    cout << ((n == 0) ? 0 : f(n-1)) << endl;    

}

int main(){

	int T;
    T = 1;
    // cin >> T;
	while(T--){
		solve();
	}
}
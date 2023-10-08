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

int cnt[SZ+1];
int spf[SZ+1];

void Sieve(){

    for(int i=1;i<=SZ;i++){
        spf[i] = i;
    }

    for(int i=2;i<=SZ;i+=2) spf[i] = 2;

    for(int i=3;i<=SZ;i+=2){
        if(spf[i]==i){
            for(int j=i;j<=SZ;j+=i) spf[j] = i;
        }
    }

}


ll mobius(ll n){

    
    ll num = 0;
    while(n!=1){
        
        ll p = spf[n];
        
        num++;
        ll alpha = 0;
        while(n%p == 0){
            n /= p;
            alpha++;
        }

        if(alpha > 1) return 0;

    }

    if(num%2 == 0) return 1;
    else if(num%2 == 1) return -1;

}

void solve() {

    ll n; cin >> n;
    vector<ll> v(n);

    ll Max = INT_MIN;
    for(auto &x: v) {
        cin >> x;
        cnt[x]++;
        Max = max(Max, x);
    }

    ll ans = 0;
    for(int i=1;i<=Max;i++){
        ll div = 0;
        ll M = mobius(i);
        if(M == 0) continue; // log(i)
        for(int j=i;j<=Max;j+=i){
            div += cnt[j];
        }
        // cout << i << " " << div << " " << mobius(i) << endl;
        ans += (div*(div-1)/2) * M;
    }

    cout << ans << endl;


}

int main(){

    Sieve();
	int T;
    T = 1;
	while(T--){
		solve();
	}
}
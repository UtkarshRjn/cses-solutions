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

typedef long double ld;

void solve() {

    ll n,k; cin >> n >> k;
    vector<ll> v(k);

    for(auto& x: v) cin >> x;

    vector<char> dp(n+1, '0');
    dp[0] = 'L';
    for(int i=1;i<=n;i++){
        for(auto e: v){
            if(i >= e && dp[i-e] == 'L'){
                dp[i] = 'W';
                break;
            }
        }
        if(dp[i] == '0') dp[i] = 'L';
    }

    string ans = "";
    for(int i=1;i<=n;i++){
        ans += dp[i];
    }

    cout << ans << endl;

}

int main(){

	int T;
    T = 1;
    // cin >> T;
	while(T--){
		solve();
	}
}
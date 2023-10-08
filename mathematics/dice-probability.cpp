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

    ll n,a,b; cin >> n >> a >> b;

    vector<ld> dp(601, 0);

    dp[0] = 1.0;
    for(int thrw = 1; thrw<=n;thrw++){
        vector<ld> dpN(601, 0);
        for(int i=1;i<=6*thrw;i++){
            for(int j=i-1;j>=i-6 & j >= 0;j--){
                dpN[i] += dp[j];
            }
            dpN[i] /= 6;
        }
        dp = dpN;
    }

    ld ans = 0;
    for(int i=a;i<=b;i++){
        ans += dp[i];
    }

    cout << fixed << setprecision(6) <<  ans << endl;

}

int main(){

	int T;
    T = 1;
    // cin >> T;
	while(T--){
		solve();
	}
}
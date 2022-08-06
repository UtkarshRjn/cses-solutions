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

const ll fac = 1e9 + 7;

int main(){
	
	ll n; cin >> n;
    vector<int> v(n);

    ll sum = 0;
    for(int& x: v){
        cin >> x;
        sum += x;
    }

    // cout << sum << endl;
    vector<vector<ll>> dp(n+1,vector<ll> (n+1));

    for(ll i=n;i>=1;i--){
        for(ll j=i;j<=n;j++){
            if(i==j) dp[i][i] = v[i-1];
            else{
                dp[i][j] = max(v[j-1] - dp[i][j-1], v[i-1] - dp[i+1][j]);
            }
        }
    }

    cout << (sum+dp[1][n])/2 << endl;

}
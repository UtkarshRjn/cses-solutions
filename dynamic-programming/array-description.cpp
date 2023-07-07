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
const int mod = 1e9+7;
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

bool isP(int ni, int nj, ll n ,ll m){

	if(ni<0 || nj <0 || ni>=n || nj>=m) return false;
	else return true;

}

void solve(){

    ll n,m; cin >> n >> m;
    vector<vector<ll>> dp(n,vector<ll>(m+2,0));

    vector<ll> v(n);
    for(auto &x: v) {
        cin >> x;
    }

    if(v[0] != 0){
        dp[0][v[0]] = 1;
    }else{
        for(int j=1;j<=m;j++) dp[0][j] = 1;
    }

    for(int i=1;i<n;i++){
        if(v[i]!=0 && v[i-1] !=0){
            if(abs(v[i] - v[i-1]) > 1){
                cout << 0 << endl;
                return;
            }
            dp[i][v[i]] = dp[i-1][v[i-1]];
        }else if(v[i]!=0 && v[i-1] == 0){
            dp[i][v[i]] = ((dp[i-1][v[i]] + dp[i-1][v[i]+1])%mod + dp[i-1][v[i]-1])%mod;
        }else if(v[i]==0 && v[i-1] != 0){
            dp[i][v[i-1]] = dp[i-1][v[i-1]];
            dp[i][v[i-1] - 1] = (v[i-1] - 1 != 0) ? dp[i-1][v[i-1]] : 0;
            dp[i][v[i-1] + 1] = (v[i-1] + 1 != m+1) ? dp[i-1][v[i-1]] : 0;
        }else{

            for(int j=1;j<=m;j++){
                dp[i][j] = ((dp[i-1][j] + dp[i-1][j+1])%mod + dp[i-1][j-1])%mod; 
            }

        }
    }

    ll sum = 0;
    for(int i=1;i<=m;i++){
        sum = (sum + dp[n-1][i])%mod;
    }
    cout << sum << endl;
}

int main(){
	solve();
}
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

    ll n,x; cin >> n >> x;
    vector<ll> wt(n);
    vector<ll> val(n);

    for(auto &x: wt)    cin >> x;
    for(auto &x: val)    cin >> x;

    vector<ll> dp(x+1,0);

    for(int i=0;i<n;i++){
        for(int j=x;j>=wt[i];j--){
            dp[j] = max(dp[j], dp[j-wt[i]] + val[i]);
        }
    }

    cout << dp[x] << endl;

}

int main(){
	solve();
}
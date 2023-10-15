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

bool lexo_dec(string a, string b) {
	return a > b;
}
 
bool isP(int ni, int nj, ll n ,ll m){
 
	if(ni<0 || nj <0 || ni>=n || nj>=m) return false;
	else return true;
 
}

ll MOD = 1e9 + 7;
vector<vector<ll> > dp;
unordered_map<ll,vector<ll> > subsets;
ll n,m;

bool isValid(ll mask){

    ll i = 0;
    for(ll count = 0; mask; mask/=2,i++){
        if(mask%2 == 0) count++;
        else if(count%2 != 0) return false; 
    }

    return ((n-i)%2 == 0);

}

void buildMap(){

    for(int mask=0;mask<pow(2,n);mask++)
        for(int Nmask=0;Nmask<pow(2,n);Nmask++)
            if(!(mask & Nmask) && isValid(Nmask|mask))
                subsets[mask].push_back(Nmask);

}

ll countWays(ll i, ll mask){

    if(dp[i][mask] != -1) 
        return dp[i][mask];
    
    if(i == m-1)
        return dp[i][mask] = isValid(mask);
    
    ll ans = 0;
    for(auto subset: subsets[mask])
        ans = (ans + countWays(i+1,subset))%MOD;

    return dp[i][mask] = ans;

}

void solve(){
 
    cin >> n >> m;

    dp.resize(m,vector<ll>(pow(2,n),-1));
    buildMap();

    cout << countWays(0,0) << endl;
   
}

int main(){
	solve();
}
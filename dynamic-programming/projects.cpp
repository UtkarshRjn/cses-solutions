
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

struct project{
    ll a,b,p;
};

void solve(){
    
    ll n; cin >> n;

    map<ll,vector<project>> end;
    vector<ll> idx;
    for(int i=0;i<n;i++){
        ll a,b,p; cin >> a >> b >> p;
        if(end.find(b) == end.end()) end[b] = {{a,b,p}};
        else end[b].push_back({a,b,p});

        idx.push_back(a);
        idx.push_back(b);
    }
    sort(idx.begin(),idx.end());

    vector<ll> dp(2*n+1,0);
    for(int i=1;i<=2*n;i++){

        dp[i] = dp[i-1];
        if(end.find(idx[i]) != end.end()){
            for(auto elem : end[idx[i]]){
                ll temp = lower_bound(idx.begin(),idx.end(),elem.a) - idx.begin();
                if(temp) temp--;
                dp[i] = max(dp[i], dp[temp] + elem.p);
            }
        }
    }
    
    cout << dp[2*n] << endl;

}

int main(){
	solve();
}
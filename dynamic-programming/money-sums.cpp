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
 
    ll n; cin >> n;
    vector<ll> v(n);
 
    ll sum = 0;
    for(auto &x: v){
        cin >> x;
        sum += x;
    }
 
    vector<ll> dp(sum+1,0);
 
    dp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=sum;j>0;j--){
            if(j - v[i] >=0){
                if(dp[j] == 0 ) dp[j] = dp[j-v[i]];
            }
        }
    }
 
    vector<ll> ans;
    for(int i=1;i<=sum;i++){
        if(dp[i]) ans.push_back(i);
    }
 
    cout << ans.size() << endl;
    for(auto &x : ans){
        cout << x << " ";
    }
    cout << endl;
}
 
int main(){
	solve();
}
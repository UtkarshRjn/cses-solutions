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
 
#define SZ 200005
#typedef pair<ll,ll> pll

ll t[8*SZ];


void build(ll v,const pll& tl ,const pll& tr, const vector<vector<char>>& arr){
 
    if(tl == tr){
        t[v] = arr[tl.first][tl.second] == '*';
    }else{
        
        ll tmy = (tl.first + tr.first)/2;
        ll tmx = (tl.second + tr.second)/2;
        build(4*v-2,tl,{tmy,tmx},arr);
        build(4*v-1,{tl.first,tmx+1}, {tmy,tr.second},arr);
        build(4*v,{tmy+1,tl.second},{tr.first,tmx},arr);
        build(4*v+1,{tmy+1,tmx+1},tr,arr);
        t[v] = t[4*v-2] + t[4*v-1] + t[4*v] + t[4*v+1];

    }
 
}

ll query(ll v, pll tl, pll tr, pll l, pll r){
 
    if(l.first > r.first || l.second > r.second) return 0;

    if(tl == l && tr == r){
        return t[v];
    }else{
        
        ll tmy = (tl.first + tr.first)/2;
        ll tmx = (tl.second + tr.second)/2;
        return query(4*v-2,tl,{tmy,tmx},l,min({tmy,tmx},r)) + 
        query(4*v-1,{tl.first,tmx+1},{tmy,tr.second},{l.first,max(tmx+1,r.second)},{min(tmy,l.first),r.second}) +
        query(4*v,{tmy+1,tl.second},{tr.first,tmx},{max(tmy+1,tr.first),l.second},{r.first,min(tmx,l.second)}) + 
        query(4*v+1,{tmy+1,tmx+1},tr,max(l,{tmy+1,tmx+1}),r);

    }
 
}

void solve() {
 
	ll n,q; cin >> n >> q;
    vector<vector<char>> v(n,vector<char>(n));
 
    for(auto &x: v) cin >> x; 
    build(1,{0,0},{n-1,n-1},v);

    while(q--){
        ll y1,x1,y2,x2; cin >> y1 >> x1 >> y2 >> x2;

        cout << query(1,{0,0},{n-1,n-1},{y1,x1},{y2,x2}) << endl;

    }



}
 
int main(){
	int T;
    T = 1;
    // cin >> T;
	while(T--){
		solve();
	}
}
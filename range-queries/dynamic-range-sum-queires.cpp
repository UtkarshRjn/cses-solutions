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

#define SZ 200005
ll t[4*SZ];

void build(vector<ll>& a, ll v, ll tl, ll tr){

    if(tl == tr){
        t[v] = a[tl];
    }else{
        ll tm = (tl + tr)/2;
        build(a, v*2, tl, tm);
        build(a,v*2+1,tm+1,tr);
        t[v] = t[v*2] + t[v*2 + 1];
    }

}

ll sum(ll v, ll tl, ll tr, ll l, ll r){

    if(l > r){
        return 0;
    }
    if(l == tl && r == tr){
        return t[v];
    }

    ll tm = (tl + tr)/2;

    return sum(v*2, tl, tm, l, min(r,tm)) + sum(v*2 + 1, tm + 1, tr, max(l,tm+1), r);

}

void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

void solve() {

    ll n,q; cin >> n >> q;
    vector<ll> v(n);

    for(auto &x : v) cin >> x;
    build(v,1,0,n-1);
    
    while(q--){
        ll t,a,b; cin >> t >> a >> b;
        if(t == 1){
            update(1,0,n-1,a-1,b);
        }else if(t == 2){
            cout << sum(1,0,n-1,a-1,b-1) << endl;
        }
    }


}

int main(){
	int T;
    T = 1;
	while(T--){
		solve();
	}
}
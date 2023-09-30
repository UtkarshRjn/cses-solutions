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


void solve() {

    ll n,q; cin >> n >> q;
    vector<ll> v(n);
    
    for(auto &x: v) cin >> x;

    ll t = ceil(sqrt(n));

    vector<ll> Min(t,INT_MAX);
    for(int i=0;i<n;i++){
        Min[i/t] = min(Min[i/t],v[i]);
    }

    while(q--){
        ll a,b; cin >> a >> b;

        a--;
        b--;
        ll MahaMin = INT_MAX;
        for(int j=a;j<min((a/t)*t+t,b+1);j++){
            MahaMin = min(MahaMin, v[j]);
        }

        for(int j=max((b/t)*t,a);j<=b;j++){
            MahaMin = min(MahaMin, v[j]);
        }

        for(int idx = a/t+1; idx<b/t; idx++){
            MahaMin = min(MahaMin, Min[idx]);
        }

        cout << MahaMin << endl;
    }

}

int main(){
	int T;
    T = 1;
	while(T--){
		solve();
	}
}
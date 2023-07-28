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

ll n;
vector<ll> numChild(200000,0);
vector<ll> sumChild(200000,0);
vector<ll> ans(200000);
unordered_map<ll,vector<ll>> adj;

void dfs(ll u, ll p) {
	
    for(auto x: adj[u]){
        if(x == p) continue;
        dfs(x,u);
        numChild[u] += numChild[x] + 1;
        sumChild[u] += sumChild[x] + numChild[x] + 1;
    }

}

void dfs2(ll u, ll p){
    if(u != 0) ans[u] = ans[p] + n - 2 * (numChild[u] + 1);
    for(auto x: adj[u]){
        if(x == p) continue;
        dfs2(x,u);
    }
}

void solve() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
    dfs(0,-1);
    ans[0] = sumChild[0];
    dfs2(0,-1);

    for(int i=0;i<n;i++) cout << ans[i] << " ";
    cout << endl;

}

int main(){
	ll T;
    T = 1;
    // cin >> T;
	while(T--){
		solve();
	}
}
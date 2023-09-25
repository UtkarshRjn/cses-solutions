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
 
int n;
vector<int> adj[SZ];
int size_orig[SZ];
int value_orig[SZ];
int SubTreeLen[SZ];
int value[SZ];
int idx[SZ];
int fenwick_tree[SZ];

void dfs(int u, int p) {
	
    int count = 0;
    for(auto x: adj[u]){
        if(x == p) continue;
        dfs(x, u);
        count += size_orig[x];
    }
    size_orig[u] = count + 1;
 
}


int query(int s){

    // query fenwick from [idx[s] , idx[s] + size[idx[s]])
    int i = idx[s];
    int sum = 0;
    for(;i>0;i-=i&-i){
        sum += fenwick_tree[i];
    }

    return sum; 

}

void update(int s, int x){
    int delta = x - value[idx[s]]; 
    value[idx[s]] = x;

    int i = idx[s];
    for(;i<=n;i+=i&-i){
        fenwick_tree[i] += delta;
    }
    // update fenwick at index idx[s] to x
}

void dfs2(int u, int p, int i){

    idx[u] = i;
    value[i] = value_orig[u];
    update(u,value[i]);
    SubTreeLen[i] = size_orig[u];
    for(auto x: adj[u]){
        if(x == p) continue;
        dfs(x,u);
    }

}

void solve() {
 
	int q; cin >> n >> q;
	
    for(int i=1;i<=n;i++){
        int v; cin >> v;
        value_orig[i] = v;
    }
    
    for (int i = 0; i < n-1; i++) {
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

    dfs2(1,0,0);
	
    // Point update of value and range query 
    // 1 s x -> is a point update which just update the value
    // 2 s -> is a range query where query is from s to s + size[s];

	while(q--){
		int t; cin >> t;
        if(t == 1){
            ll s; cin >> s;
            cout << query(s) << endl;
        }else{
            ll s, x; cin >> s >> x;
            update(s,x);
        }
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
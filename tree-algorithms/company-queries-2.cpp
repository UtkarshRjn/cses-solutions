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

vector<int> adj[SZ];
vector<int> depth(SZ);
vector<int> parent(SZ,0);
vector<vector<int>> up(SZ,vector<int>(21,0));
int n;

void dfs(int u, int p, int d) {
	
    parent[u] = p;
	depth[u] = d;
    for(auto x: adj[u]){
        if(x == p) continue;
        dfs(x, u, d+1);
    }

}

void preprocess_LCA(){

	dfs(1, 0, 0);

	for(int v=1;v<=n;v++){
		up[v][0] = parent[v];
	}

	for(int v=1;v<=n;v++){ // O(n)
		for(int j=1;1<<j <= n;j++){ // O(nlogn)
			up[v][j] = up[up[v][j-1]][j-1];
		}
	}

}

int LCA(int u, int v){

	if(depth[u] < depth[v]){
		swap(u,v);
	}

	int k = depth[u] - depth[v];
	for(int j=20;j>=0;j--){
		if(k&(1<<j)){
			u = up[u][j];
		}
	}

	if(u == v) return u;

	for(int j=20;j>=0;j--){
		if(up[u][j] != up[v][j]){
			u = up[u][j];
			v = up[v][j];
		}
	}

	return up[u][0];

}

void solve() {

	int q; cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		int a; cin >> a;
		adj[a].push_back(i);
		adj[i].push_back(a);
	}
	
    preprocess_LCA();

	while(q--){
		int u,v; cin >> u >> v;

		cout << LCA(u,v) << endl;		
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
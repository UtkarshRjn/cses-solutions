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

bool isP(int ni, int nj, ll n ,ll m){

	if(ni<0 || nj <0 || ni>=n || nj>=m) return false;
	else return true;

}

void solve(){
	

    // Do dfs and color odd even, if odd cycle found say IMPOSSIBLE
	ll n,m;
    cin >> n >> m;
    vector<vector<ll>> adj(n);

    auto t = m;
    while(t--){
        int a,b;
        cin >> a >> b;

        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    vector<bool> vis(n,false);
    stack<ll> q;
    vector<ll> color(n);
    
    for(ll i=0;i<n;i++){
        q.push(i);
    }
    
    vis[0] = true;
    color[0] = 0;
    while(!q.empty()){

        auto t = q.top();
        q.pop();

        for(auto x : adj[t]){
            
            if(!vis[x]){
                q.push(t);
                color[x] = 1 - color[t];
                q.push(x);
                vis[x] = true;
            }else{
                if(color[x] == color[t]){
                    cout << "IMPOSSIBLE" << endl;
                    return;
                }
            }

        }

    }

    for(auto i: color){
        cout << i+1 << " ";
    }
    cout << endl;

}

int main(){
	solve();
}
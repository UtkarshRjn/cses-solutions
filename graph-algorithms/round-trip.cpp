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

int WHITE = 0;
int GRAY = 1;
int BLACK = 2;

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
    vector<ll> dist(n);
    vector<ll> p(n);

    bool cycle = false;
    for(int i=0;i<t;i++){

        if(!vis[t]){
    
            for(auto x : adj[t]){
                
                if(vis[x] == WHITE){
                    
                }else if(vis[x] == GRAY){
                    
                    cycle = true;

                }

            }

        }

    }

    if(!cycle){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    ll u = 0;
    ll k = dist[0];
    vector<ll> ans(k+2);
    cout << k+2 << endl;
    ans[0] = u+1;
    for(int i=k+1; i>0 ; i--){
        ans[i] = u+1;
        u = p[u];
    }

    for(auto elem: ans){
        cout << elem << " ";
    }
    
    cout << endl;

}

int main(){
	solve();
}
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

void dfs(int src, unordered_map<ll,vector<ll>>& adj, vector<ll>& toLeaf, vector<ll>& maxLength, vector<ll>& parent){

    for(auto n: adj[src]){
        if(n != parent[src]){
            parent[n] = src;
            dfs(n, adj, toLeaf, maxLength, parent);
            toLeaf[src] = max(toLeaf[src], toLeaf[n]+1);
        }
    }

    multiset<ll, greater<ll>> childLength;
    for(auto n: adj[src]){
        if(n != parent[src]){
            childLength.insert(toLeaf[n]+1);
        }
    }

    if(childLength.size() == 0){
        toLeaf[src] = 0;
        maxLength[src] = 0;
    }
    else if(childLength.size() == 1) maxLength[src] = *childLength.begin();
    else maxLength[src] = *childLength.begin() + *(++childLength.begin());

}

void solve(){
    
    ll n;cin >> n;
    unordered_map<ll,vector<ll>> adj;
    for(int i=0;i<n-1;i++){
        ll a,b;cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    vector<ll> toLeaf(n,0), maxLength(n,0);
    vector<ll> parent(n,-1);

    dfs(0,adj,toLeaf,maxLength,parent);

    sort(maxLength.begin(),maxLength.end(), greater<ll>());

    cout << maxLength[0] << endl;

}

int main(){
	ll T;
    T = 1;
    // cin >> T;
	while(T--){
		solve();
	}
}
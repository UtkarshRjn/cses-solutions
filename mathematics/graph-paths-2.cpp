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

#define SZ 1000005
const ll MOD = 1e9 + 7;
const ll INF = 4e18;

vector<vector<ll> > matmul2(const vector<vector<ll> >& mat1,const vector<vector<ll> >& mat2){
    
    int m = mat1.size();
    int n = mat1[0].size();
    int p = mat2[0].size();
    vector<vector<ll> > ans(m,vector<ll>(p, INF));
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            for(int k=0;k<n;k++){
                ans[i][j] = min(ans[i][j], mat1[i][k] + mat2[k][j]);
            }
        }
    }

    return ans;

}

vector<vector<ll> > Matpow(vector<vector<ll> >& mat, ll n){ 
    
    vector<vector<ll> > ans = mat;
    n--;
    while(n){
        
        if(n%2) ans = matmul2(ans, mat);
        mat = matmul2(mat, mat);
        n/=2;

    }

    return ans;

}

void solve() {

    ll n,m,k; cin >> n >> m >> k;
    vector<vector<ll> > adj(n, vector<ll>(n,INF));

    while(m--){
        ll a, b, w; cin >> a >> b >> w;
        adj[a-1][b-1] = min(w,adj[a-1][b-1]);
    }

    adj = Matpow(adj,k);
    
    if(adj[0][n-1] == INF){
        cout << -1 << endl;
        return;
    } 
    
    cout << adj[0][n-1] << endl;

}

int main(){

	int T;
    T = 1;
    // cin >> T;
	while(T--){
		solve();
	}
}